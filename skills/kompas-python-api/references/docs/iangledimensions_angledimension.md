# AngleDimension - Угловой размер, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Коллекции размеров ](bb2356897.html) > [Интерфейс AngleDimensions ](iangledimensions.html) > [IAngleDimensions - свойства ](iangledimensions_props.html) |  Scroll [ [ [ ](iangledimensions_methods.html "К следующему разделу")](iangledimensions_props.html "На уровень выше")](iangledimensions_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iangledimensions.html)

Тип данных: указатель на интерфейс углового размера [IAngleDimension](iangledimension.html)

Синтаксис Automation:

AngleDimension = iObject.AngleDimension( Index ); | Получить свойство([* ](1.html))  
---|---  
AngleDimension = iObject.GetAngleDimension( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_AngleDimension( Index, &AngleDimension ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс размера в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс размера.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
