# Revit API — типовые ошибки

## 1. `LookupParameter` возвращает `None`

Причины:
- Параметр называется иначе (проверить точное имя, включая префикс `RI_…`).
- Параметр есть только у типа, а не у экземпляра (или наоборот). Читать из обоих:
  ```python
  for src in (inst, tp):
      p = src.LookupParameter(name)
      if p is not None: break
  ```
- Параметр отсутствует в проекте (общий параметр не подключён).

## 2. `Parameter is read-only`

```python
p.IsReadOnly  # True -> Set() не сработает
```
Причины: вычисляемый параметр, параметр проекта, системный параметр.

## 3. Несовпадение типа

```python
p.StorageType  # String / Integer / Double
```
Нельзя писать строку в `Double` и наоборот. Для `Double` — значения в футах, если это длина; для вывода — `AsValueString()`.

## 4. Пустой `FilteredElementCollector`

- Передан не тот документ (например, документ связи).
- Не тот класс (`View` vs `ViewSchedule`).
- Коллектор по виду вернёт только элементы, видимые на этом виде — для сбора по всей модели использовать `FilteredElementCollector(doc)`.

## 5. «Документ не активен» / `revit.doc is None`

Открыть документ до запуска скрипта или взять `__revit__.ActiveUIDocument.Document`.

## 6. Ошибка в транзакции

- `Transaction started already` — вложенный `Start()`.
- `Cannot modify ... outside transaction` — забыт `Start()`.
- После `RollBack()` — не продолжать писать.

## 7. Excel через COM не работает

```python
import System
xl_t = System.Type.GetTypeFromProgID("Excel.Application")
xl   = System.Activator.CreateInstance(xl_t)
```
Требует установленный MS Excel. На серверах без Office — не сработает; альтернатива — openpyxl (через IronPython не всегда доступен).

## 8. Кириллица ломается в консоли

Все строковые литералы писать с префиксом `u"…"`:
```python
print(u"Привет")
```

## 9. Скрипт «молча» ничего не сделал

Проверить `pyrevit → Output`: там `print()`, трейсы и результаты `forms.alert`. Часто виноват `script.exit()` в неожиданной ветке.
