# pyRevit — базовые инструменты

## Диалоги

```python
from pyrevit import forms

# Простое сообщение
forms.alert(u"Готово")

# Выбор из списка (одиночный)
name = forms.SelectFromList.show(
    [u"А", u"Б", u"В"],
    title=u"Выбор",
    button_name=u"ОК",
    multiselect=False)

# Множественный выбор
names = forms.SelectFromList.show(
    list_of_strings,
    title=u"Выберите",
    button_name=u"Далее",
    multiselect=True)
# -> list или str (если multiselect=False)

# Выбор файла для сохранения
out_path = forms.save_file(file_ext='xlsx', default_name=u"Отчёт.xlsx")
```

## Выход

```python
from pyrevit import script
script.exit()   # корректно завершить скрипт
```

## Output (окно с логами и таблицами)

```python
out = script.get_output()

out.print_md(u"# Заголовок")
out.print_table(
    table_data=[[u"a", 1], [u"b", 2]],
    columns=[u"Ключ", u"Значение"])

# Кликабельные ссылки на элементы Revit
out.linkify(element.Id, title=u"ID {}".format(int(element.Id.IntegerValue)))

# В markdown
out.print_md(u"Элемент: {}".format(
    out.linkify(el.Id, title=u"клик"))
)
```

## Печать в консоль pyRevit

```python
print(u"Служебное сообщение")   # идёт в Output
```
