# -*- coding: utf-8 -*-
__title__ = "Проверка марок на планах"
__doc__   = "Сравнивает количество марок опор в модели с тегами и заметками на планах"

import clr
clr.AddReference('RevitAPI')
clr.AddReference('RevitAPIUI')
clr.AddReference('RevitServices')
clr.AddReference('System')

from Autodesk.Revit.DB import *
from pyrevit import forms, script, revit
import re
from collections import defaultdict


def get_str(el, name):
    if el is None:
        return u""
    p = el.LookupParameter(name)
    if p is None:
        return u""
    try:
        if p.StorageType == StorageType.String:
            return p.AsString() or u""
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


RE_MARK = re.compile(u"^[А-ЯЁA-Z]{2,6}\\d+[УU]?$", re.UNICODE)


def as_mark(text):
    if not text:
        return None
    t = text.strip().upper().replace(u" ", u"").replace(u"-", u"")
    return t if RE_MARK.match(t) else None


doc = revit.doc
if doc is None:
    forms.alert(u"Нет активного документа Revit.")
    script.exit()

# --- модель ---
model_counts = defaultdict(int)
for inst in FilteredElementCollector(doc).OfClass(FamilyInstance):
    tp = doc.GetElement(inst.GetTypeId())
    if tp is None:
        continue
    mk = first_str(inst, tp, u"RI_ОП_02_Марка").strip()
    if mk:
        model_counts[mk] += 1

# --- планы ---
plan_views = [
    v for v in FilteredElementCollector(doc).OfClass(View)
    if not v.IsTemplate and u"{}".format(v.ViewType) in (
        u"FloorPlan", u"CeilingPlan", u"EngineeringPlan")
]
if not plan_views:
    forms.alert(u"Нет планов в модели.")
    script.exit()

selected = forms.SelectFromList.show(
    [v.Name for v in plan_views],
    title=u"Планы для проверки",
    button_name=u"Проверить",
    multiselect=True)
if not selected:
    script.exit()
if isinstance(selected, str):
    selected = [selected]

plan_counts = defaultdict(int)
for v in plan_views:
    if v.Name not in selected:
        continue
    for tag in FilteredElementCollector(doc, v.Id).OfClass(IndependentTag):
        mk = as_mark(tag.TagText)
        if mk:
            plan_counts[mk] += 1
    for note in FilteredElementCollector(doc, v.Id).OfClass(TextNote):
        for line in re.split(u"[\\r\\n]+", note.Text or u""):
            mk = as_mark(line)
            if mk:
                plan_counts[mk] += 1

# --- отчёт ---
all_marks = sorted(set(model_counts) | set(plan_counts))
out = script.get_output()
out.print_md(u"# Проверка марок на планах")

tbl = []
problems = 0
for mk in all_marks:
    mc = model_counts.get(mk, 0)
    pc = plan_counts.get(mk, 0)
    if mc == pc:
        st = u"OK"
    elif pc == 0:
        st = u"НЕТ на планах"
        problems += 1
    elif mc == 0:
        st = u"ЛИШНЯЯ на планах"
        problems += 1
    else:
        st = u"РАСХОЖДЕНИЕ"
        problems += 1
    tbl.append([mk, mc, pc, st])

out.print_table(
    table_data=tbl,
    columns=[u"Марка", u"В модели", u"На планах", u"Статус"])

forms.alert(u"Расхождений: {}\nПодробности в Output.".format(problems))
