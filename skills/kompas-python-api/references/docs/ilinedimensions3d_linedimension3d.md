# LineDimension3D - Указатель на линейный размер, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) > [Интерфейс ILineDimensions3D ](ilinedimensions3d.html) > [ILineDimensions3D - свойства ](ilinedimensions3d_props.html) |  Scroll [ [ [ ](ilinedimensions3d_methods.html "К следующему разделу")](ilinedimensions3d_props.html "На уровень выше")](ilinedimensions3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilinedimensions3d.html)

Тип данных: указатель на интерфейс линейного размера [IBaseLineDimension3D](ibaselinedimension3d.html)

Синтаксис Automation:

LineDimension = iObject.LineDimension3D( Index ); | Получить свойство ([* ](1.html))  
---|---  
LineDimension = iObject.GetLineDimension3D( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LineDimension3D( Index, &LineDimension ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс размера в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс размера.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
