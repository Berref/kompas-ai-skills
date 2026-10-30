# Интерфейс IDrawingTable

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) |  Scroll [ [ [ ](idrawingtable_props.html "К следующему разделу")](bb3219840.html "На уровень выше")](icutline_y2.html "К предыдущему разделу")  
---|---  
  
Интерфейс таблицы на чертеже.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IDrawingTable](idrawingtable.html)

[ITable](itable.html)

Примечание:

1\. Получить интерфейс можно, используя свойство интерфейса коллекции таблиц [IDrawingTables::DrawingTable](idrawingtables_drawingtable.html).

2\. Посредством вызова метода [IUnknown::QueryInterface](recomendation.html) интерфейс позволяет получить интерфейс сетки таблицы [ITable](itable.html).

3\. Для того, чтобы сузить текст в ячейке таблицы, необходимо:

•снять признак запрета на редактирование ячейки с помощью свойства [ICellFormat::ReadOnly](icellformat_readonly.html) и изменить текст,

•вызвать метод [IDrawingObject::Update,](idrawingobject_update.html)

•установить признак запрета на редактирование ячейки,

•вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

[IDrawingTable - свойства ](idrawingtable_props.html)

[IDrawingTable - методы ](idrawingtable_methods.html)
