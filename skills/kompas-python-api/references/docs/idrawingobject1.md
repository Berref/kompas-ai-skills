# Интерфейс IDrawingObject1

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Ограничения ](bb2391397.html) |  Scroll [ [ [ ](idrawingobject1_props.html "К следующему разделу")](bb2391397.html "На уровень выше")](iparametriticconstraint_delete.html "К предыдущему разделу")  
---|---  
  
Дополнительный интерфейс для графических объектов.

Иерархия:

IDispatch

[IDrawingObject1](idrawingobject1.html)

Примечание:

1\. Дополнительный интерфейс для графических объектов. Данный интерфейс можно получить у интерфейса графического объекта [IDrawingObject](idrawingobject.html) посредством вызова метода [IUnknown::QueryInterface (const GUID far& IID, void** pif)](recomendation.html).

2\. Интерфейс позволяет выполнить следующие действия:

•получить массив ограничений для данного графического объекта,

•добавить новое ограничение,

•ассоциировать данный графический объект с другими объектами,

•удалить все ограничения.

Подразделы:

[IDrawingObject1 - свойства ](idrawingobject1_props.html)

[IDrawingObject1 - методы ](idrawingobject1_methods.html)
