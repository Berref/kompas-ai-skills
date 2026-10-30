# DiametralDimension3D - Указатель на диаметральный размер, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) > [Интерфейс IDiametralDimensions3D ](idiametraldimensions3d.html) > [IDiametralDimensions3D - свойства ](idiametraldimensions3d_props.html) |  Scroll [ [ [ ](idiametraldimensions3d_methods.html "К следующему разделу")](idiametraldimensions3d_props.html "На уровень выше")](idiametraldimensions3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idiametraldimensions3d.html)

Тип данных: указатель на интерфейс диаметрального размера [IDiametralDimension3D](idiametraldimension3d.html)

Синтаксис Automation:

DiametralDimension = iObject.DiametralDimension3D( Index ); | Получить свойство ([* ](1.html))  
---|---  
DiametralDimension = iObject.GetDiametralDimension3D( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DiametralDimension3D( Index, &DiametralDimension ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | Индекс размера в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс размера.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
