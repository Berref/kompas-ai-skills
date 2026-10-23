---
name: revit-python-api
description: Разработка и отладка Python-скриптов для Autodesk Revit через pyRevit / Revit API (IronPython, .NET через clr). Используйте при задачах автоматизации Revit — сбор элементов, чтение/запись параметров, экспорт в Excel, работа со спецификациями, тегами, аннотациями.
tags:
  - revit
  - pyrevit
  - autodesk
  - bim
  - revit-api
  - ironpython
  - filtered-element-collector
when_to_use: >
  Используй этот навык, когда пользователь просит написать, исправить или объяснить
  Python-скрипт для Autodesk Revit: сбор элементов по параметрам, чтение/запись
  параметров экземпляра или типа, выгрузка в Excel, проверка маркировок/тегов,
  присвоение позиций по полям сортировки спецификации.
license: MIT
metadata:
  author: Berref
  version: 1.0.0

# Revit Python API Skill

Помощник по написанию скриптов для Autodesk Revit на Python (IronPython) с использованием pyRevit и Revit API.

## 0. Жёсткие правила

1. **Среда.** Windows + установленный Revit (2020+) + pyRevit. Без Revit API скрипт не запустится — не обещайте пользователю запуск «где угодно».
2. **Подключение.** Всегда через .NET / IronPython:
   ```python
   import clr
   clr.AddReference('RevitAPI')
   clr.AddReference('RevitAPIUI')
   clr.AddReference('RevitServices')
   from Autodesk.Revit.DB import *
   from pyrevit import forms, script, revit
   ```
3. **Документ.** Использовать `revit.doc`, а не COM-Dispatch:
   ```python
   doc = revit.doc
   if doc is None:
       doc = __revit__.ActiveUIDocument.Document
   ```
4. **Транзакции.** Любая запись в модель — только внутри `Transaction`. Чтение — без транзакции.
5. **Не выдумывать API.** Если не уверены в имени класса/метода — искать в `RevitAPI.xml` (лежит рядом с установленным Revit) или в документации Autodesk. Не сочинять методы.
6. **Не путать с КОМПАС.** Никаких `pythoncom.CoInitialize()`, `Dispatch`, `KompasObject`. Это разные миры.

## 1. Когда использовать

- Собрать элементы по параметрам (`RI_ПП_Зона`, `RI_ОП_02_Марка` и т.п.).
- Прочитать/записать параметры экземпляра или типа.
- Сформировать отчёт или выгрузить в Excel.
- Проверить марки/теги на планах.
- Присвоить позиции по полям сортировки спецификации.
- Найти дубли по составу.

## 2. Типовой каркас скрипта

```python
# -*- coding: utf-8 -*-
__title__ = "Название"
__doc__   = "Что делает скрипт"

import clr
clr.AddReference('RevitAPI')
clr.AddReference('RevitAPIUI')
clr.AddReference('RevitServices')
clr.AddReference('System')

from Autodesk.Revit.DB import *
from pyrevit import forms, script, revit

doc = revit.doc
if doc is None:
    forms.alert(u"Нет активного документа Revit.")
    script.exit()

# ... логика ...

forms.alert(u"Готово")
```

## 3. Справочные материалы

- `references/api-cheatsheet.md` — основные классы и методы Revit API.
- `references/pyrevit-basics.md` — `forms`, `script.get_output()`, `linkify`.
- `references/transactions.md` — шаблон безопасной транзакции.
- `references/troubleshooting.md` — типовые ошибки и их лечение.

## 4. Примеры

- `examples/basic_scan.py`         — скан модели, `FilteredElementCollector`, параметры.
- `examples/export_excel.py`      — выгрузка в Excel через COM.
- `examples/tag_check.py`         — проверка тегов на планах (`IndependentTag`, `TextNote`).
- `examples/position_assignment.py` — присвоение позиций по полям сортировки спецификации.

## 5. Что делать, если не работает

1. Открыть `references/troubleshooting.md`.
2. Проверить: тот ли документ, есть ли параметр, не `IsReadOnly`, совпадает ли `StorageType`.
3. Убедиться, что транзакция `Start()`/`Commit()` соблюдена.
4. Посмотреть `pyrevit → Output` — там `print()` и трейсы.
