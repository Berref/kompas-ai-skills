# AngleDimension3D - Указатель на угловой размер, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) > [Интерфейс IAngleDimensions3D ](iangledimensions3d.html) > [IAngleDimensions3D - свойства ](iangledimensions3d_props.html) |  Scroll [ [ [ ](iangledimensions3d_methods.html "К следующему разделу")](iangledimensions3d_props.html "На уровень выше")](iangledimensions3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iangledimensions3d.html)

Тип данных: указатель на интерфейс углового размера [IAngleDimension3D](iangledimension3d.html)

Синтаксис Automation:

AngleDimension = iObject.AngleDimension3D( Index ); | Получить свойство ([* ](1.html))  
---|---  
AngleDimension = iObject.GetAngleDimension3D( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_AngleDimension3D( Index, &AngleDimension ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс размера в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс размера.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
