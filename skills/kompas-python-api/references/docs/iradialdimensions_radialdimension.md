# RadialDimension - Радиальный размер, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Коллекции размеров ](bb2356897.html) > [Интерфейс IRadialDimensions ](iradialdimensions.html) > [IRadialDimensions - свойства ](iradialdimensions_props.html) |  Scroll [ [ [ ](iradialdimensions_methods.html "К следующему разделу")](iradialdimensions_props.html "На уровень выше")](iradialdimensions_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iradialdimensions.html)

Тип данных: указатель на интерфейс радиального размера [IRadialDimension](iradialdimension.html)

Синтаксис Automation:

RadialDimension = iObject.RadialDimension( Index ); | Получить свойство([* ](1.html))  
---|---  
RadialDimension = iObject.GetRadialDimension( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_RadialDimension( Index, &RadialDimension ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс размера в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс размера.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
