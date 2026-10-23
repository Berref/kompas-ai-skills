# Транзакции в Revit

Любая **запись** в модель выполняется в `Transaction`. Чтение — без транзакции.

## Базовый шаблон

```python
from Autodesk.Revit.DB import Transaction

t = Transaction(doc, u"Имя транзакции")
t.Start()
try:
    p = element.LookupParameter(u"RI_ОП_01_Номер детали")
    if p is not None and not p.IsReadOnly:
        p.Set(u"12")
    t.Commit()
except Exception as ex:
    t.RollBack()
    print(u"Ошибка: {}".format(ex))
```

## Правила

1. **Одна транзакция — одна логическая операция.** Не нужно оборачивать весь скрипт.
2. **`RollBack` обязателен** в `except` — иначе модель останется в подвешенном состоянии.
3. **Нельзя `Start()` внутри `Start()`.** Если уже в транзакции — сначала `Commit()`/`RollBack()`.
4. **`Commit()` возвращает `TransactionStatus`.** Проверять только при необходимости.
5. **Внешние приложения** (Excel через COM) — вне транзакции, но их результат можно записать в модель внутри транзакции, если нужно.

## Пример: массовая запись параметров

```python
t = Transaction(doc, u"Позиция — присвоение номеров")
t.Start()
written = 0
errors = []
try:
    for row in rows:
        try:
            p = row["element"].LookupParameter(param_name)
            if p is None or p.IsReadOnly:
                continue
            p.Set(str(row["position"]))
            written += 1
        except Exception as ex:
            errors.append(u"ID {}: {}".format(
                int(row["element"].Id.IntegerValue), ex))
    t.Commit()
except Exception as ex:
    t.RollBack()
    errors.append(u"Критическая ошибка: {}".format(ex))
```
