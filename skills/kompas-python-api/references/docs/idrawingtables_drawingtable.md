# DrawingTable - Указатель на таблицу, заданную по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс IDrawingTables ](idrawingtables.html) > [IDrawingTables - свойства ](idrawingtables_props.html) |  Scroll [ [ [ ](idrawingtables_methods.html "К следующему разделу")](idrawingtables_props.html "На уровень выше")](idrawingtables_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingtables.html)

Тип данных: указатель на интерфейс [IDrawingTable](idrawingtable.html)

Синтаксис Automation:

DrawingTable = iObject.DrawingTable( Index ); | Получить свойство([* ](1.html))  
---|---  
DrawingTable = iObject.GetDrawingTable( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DrawingTable( Index, &DrawingTable ) | Получить свойство  
---|---  
  
Входные параметры:

Index | \- VT_I4 - индекс объекта.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
