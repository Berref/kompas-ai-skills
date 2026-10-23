# -*- coding: utf-8 -*-
__title__ = "Базовый скан модели"
__doc__   = "Собирает экземпляры семейств по параметру RI_ПП_Зона и печатает в Output"

import clr
clr.AddReference('RevitAPI')
clr.AddReference('RevitAPIUI')
clr.AddReference('RevitServices')
clr.AddReference('System')

from Autodesk.Revit.DB import *
from pyrevit import forms, script, revit


def get_str(el, name):
    if el is None:
        return u""
    p = el.LookupParameter(name)
    if p is None:
        return u""
    try:
        if p.StorageType == StorageType.String:
            return p.AsString() or u""
        if p.StorageType == StorageType.Integer:
            return u"{}".format(p.AsInteger())
        if p.StorageType == StorageType.Double:
            return p.AsValueString() or u""
    except:
        pass
    return u""


def first_str(inst, tp, *names):
    for n in names:
        v = get_str(inst, n)
        if v:
            return v
    for n in names:
        v = get_str(tp, n)
        if v:
            return v
    return u""


doc = revit.doc
if doc is None:
    forms.alert(u"Нет активного документа Revit.")
    script.exit()

out = script.get_output()
out.print_md(u"# Скан модели")

rows = []
for inst in FilteredElementCollector(doc).OfClass(FamilyInstance):
    tp = doc.GetElement(inst.GetTypeId())
    if tp is None:
        continue

    zone = first_str(inst, tp, u"RI_ПП_Зона").strip()
    if not zone:
        continue

    mark = first_str(inst, tp, u"RI_ОП_02_Марка").strip()
    rows.append([
        out.linkify(inst.Id, title=u"ID {}".format(int(inst.Id.IntegerValue))),
        zone,
        mark or u"—",
    ])

if not rows:
    forms.alert(u"Ничего не найдено по параметру RI_ПП_Зона.")
    script.exit()

out.print_table(
    table_data=rows,
    columns=[u"Элемент", u"ОПС (RI_ПП_Зона)", u"Марка"])

forms.alert(u"Элементов: {}".format(len(rows)))
