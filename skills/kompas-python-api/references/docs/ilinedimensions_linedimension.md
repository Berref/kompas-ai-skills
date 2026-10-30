# LineDimension - Линейный размер, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Коллекции размеров ](bb2356897.html) > [Интерфейс ILineDimensions ](ilinedimensions.html) > [ILineDimensions - свойства ](ilinedimensions_props.html) |  Scroll [ [ [ ](ilinedimensions_methods.html "К следующему разделу")](ilinedimensions_props.html "На уровень выше")](ilinedimensions_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilinedimensions.html)

Тип данных: указатель на интерфейс линейного размера [ILineDimension](ilinedimension.html)

Синтаксис Automation:

LineDimension = iObject.LineDimension( Index ); | Получить свойство([* ](1.html))  
---|---  
LineDimension = iObject.GetLineDimension( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LineDimension( Index, &LineDimension ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс размера в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс размера.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
