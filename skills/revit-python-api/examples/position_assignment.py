# -*- coding: utf-8 -*-
__title__ = "Присвоение позиций по спецификации"
__doc__   = "Проставляет порядковые позиции по полям сортировки активной спецификации"

import clr
clr.AddReference('RevitAPI')
clr.AddReference('RevitAPIUI')
clr.AddReference('RevitServices')
clr.AddReference('System')

from Autodesk.Revit.DB import *
from pyrevit import forms, script, revit
import re


PARAM_NAME = u"RI_ОП_01_Номер детали"


def natural_key(value):
    text = u"{}".format(value)
    key = []
    for part in re.split(r"(\d+)", text):
        if part == u"":
            continue
        key.append((0, int(part)) if part.isdigit() else (1, part.lower()))
    return tuple(key)


def get_field_value(el, name):
    p = el.LookupParameter(name)
    if p is None:
        return u""
    v = p.AsValueString()
    if v is None:
        v = p.AsString()
    return v or u""


doc = revit.doc
uidoc = __revit__.ActiveUIDocument
schedule = uidoc.ActiveView

if not isinstance(schedule, ViewSchedule):
    forms.alert(u"Откройте спецификацию и запустите скрипт.")
    script.exit()

sort_fields = []
group_fields = []
for f in schedule.Definition.GetSortGroupFields():
    fld = schedule.Definition.GetField(f.FieldId)
    name = fld.GetName()
    sort_fields.append(name)
    try:
        if f.ShowHeader:
            group_fields.append(name)
    except:
        pass

if not sort_fields:
    forms.alert(u"У спецификации нет полей сортировки.")
    script.exit()

elements = list(FilteredElementCollector(doc, schedule.Id).ToElements())
if not elements:
    forms.alert(u"В спецификации нет элементов.")
    script.exit()

rows = []
for el in elements:
    full = tuple(natural_key(get_field_value(el, n)) for n in sort_fields)
    grp = tuple(natural_key(get_field_value(el, n)) for n in group_fields)
    rows.append({"el": el, "full": full, "grp": grp})

rows.sort(key=lambda r: r["full"])

pos = 0
prev_full = None
prev_grp = None
for r in rows:
    if prev_grp is None or r["grp"] != prev_grp:
        pos = 1
        prev_grp = r["grp"]
        prev_full = r["full"]
    elif r["full"] != prev_full:
        pos += 1
        prev_full = r["full"]
    r["pos"] = pos

t = Transaction(doc, u"Позиции по спецификации")
t.Start()
written = 0
try:
    for r in rows:
        p = r["el"].LookupParameter(PARAM_NAME)
        if p is None or p.IsReadOnly:
            continue
        p.Set(str(r["pos"]))
        written += 1
    t.Commit()
except Exception as ex:
    t.RollBack()
    forms.alert(u"Ошибка транзакции:\n{}".format(ex))
    script.exit()

forms.alert(u"Заполнено: {}\nСпецификация: {}".format(written, schedule.Name))
