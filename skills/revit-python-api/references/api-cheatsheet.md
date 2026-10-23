# Revit API — шпаргалка

## Документ

```python
doc = revit.doc
tp  = doc.GetElement(inst.GetTypeId())
```

## Сбор элементов

```python
# Все экземпляры семейств
FilteredElementCollector(doc).OfClass(FamilyInstance)

# Все виды-планы
FilteredElementCollector(doc).OfClass(View)

# Элементы в конкретном виде
FilteredElementCollector(doc, view.Id).OfClass(IndependentTag)

# Все спецификации
FilteredElementCollector(doc).OfClass(ViewSchedule)
```

## Параметры

```python
p = element.LookupParameter("Имя")
if p is None: ...

p.StorageType   # StorageType.String / Integer / Double
p.AsString()    # для String
p.AsInteger()   # для Integer
p.AsDouble()    # для Double (в футах/единицах модели)
p.AsValueString() # отформатированная строка
p.IsReadOnly
p.Set(new_value)
```

## Имя элемента / типа / семейства

```python
try:    name = Element.Name.__get__(el)
except: name = el.Name

try:    fam_name = Element.Name.__get__(tp.Family)
except: fam_name = tp.Family.Name
```

## Встроенные параметры

```python
el.get_Parameter(BuiltInParameter.SCHEDULE_LEVEL_PARAM)
el.get_Parameter(BuiltInParameter.SYMBOL_NAME_PARAM)
```

## Спецификации

```python
sched = view  # ViewSchedule
for f in sched.Definition.GetSortGroupFields():
    f.FieldId
    f.ShowHeader                # заголовок группы
    fld = sched.Definition.GetField(f.FieldId)
    fld.GetName()
```

## Теги и заметки

```python
tag.TagText
tag.GetTaggedLocalElementIds()   # -> список ElementId

note = TextNote
note.Text
```

## ID

```python
int(el.Id.IntegerValue)
```

## Тип вида

```python
vt = view.ViewType
name = u"{}".format(vt)  # "FloorPlan", "CeilingPlan", ...
```
