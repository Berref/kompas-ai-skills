# -*- coding: utf-8 -*-
__title__ = "Экспорт таблицы в Excel"
__doc__   = "Собирает марки опор и выгружает в Excel через COM"

import clr
clr.AddReference('RevitAPI')
clr.AddReference('RevitAPIUI')
clr.AddReference('RevitServices')
clr.AddReference('System')

from Autodesk.Revit.DB import *
from pyrevit import forms, script, revit
import System


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


def write_excel(path, header, rows):
    xl_t = System.Type.GetTypeFromProgID("Excel.Application")
    xl = System.Activator.CreateInstance(xl_t)
    xl.Visible = False
    xl.DisplayAlerts = False
    try:
        wb = xl.Workbooks.Add()
        while wb.Worksheets.Count > 1:
            wb.Worksheets(wb.Worksheets.Count).Delete()
        ws = wb.Worksheets(1)
        ws.Name = u"Марки"

        for c, h in enumerate(header):
            cell = ws.Cells(1, c + 1)
            cell.Value = h
            cell.Font.Bold = True

        for r_idx, row in enumerate(rows):
            for c_idx, v in enumerate(row):
                if v == u"" or v is None:
                    continue
                ws.Cells(r_idx + 2, c_idx + 1).Value = v

        wb.SaveAs(path)
        wb.Close(False)
    finally:
        xl.Quit()


doc = revit.doc
if doc is None:
    forms.alert(u"Нет активного документа Revit.")
    script.exit()

counts = {}
for inst in FilteredElementCollector(doc).OfClass(FamilyInstance):
    tp = doc.GetElement(inst.GetTypeId())
    if tp is None:
        continue
    mark = first_str(inst, tp, u"RI_ОП_02_Марка").strip()
    if not mark:
        continue
    counts[mark] = counts.get(mark, 0) + 1

if not counts:
    forms.alert(u"Нет элементов с маркой RI_ОП_02_Марка.")
    script.exit()

rows = [[mk, counts[mk]] for mk in sorted(counts.keys())]

out_path = forms.save_file(file_ext='xlsx', default_name=u"Марки_опор.xlsx")
if not out_path:
    script.exit()

write_excel(out_path, [u"Марка", u"Количество"], rows)
forms.alert(u"Готово:\n{}".format(out_path))
