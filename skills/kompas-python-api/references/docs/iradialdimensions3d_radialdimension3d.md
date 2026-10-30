# RadialDimension3D - Указатель на радиальный размер, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) > [Интерфейс IRadialDimensions3D ](iradialdimensions3d.html) > [IRadialDimensions3D - свойства ](iradialdimensions3d_props.html) |  Scroll [ [ [ ](iradialdimensions3d_methods.html "К следующему разделу")](iradialdimensions3d_props.html "На уровень выше")](iradialdimensions3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iradialdimensions3d.html)

Тип данных: указатель на интерфейс радиального размера [IRadialDimension3D](iradialdimension3d.html)

Синтаксис Automation:

RadialDimension = iObject.RadialDimension3D( Index ); | Получить свойство ([* ](1.html))  
---|---  
RadialDimension = iObject.GetRadialDimension3D( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_RadialDimension3D( Index, &RadialDimension ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс размера в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс размера.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
