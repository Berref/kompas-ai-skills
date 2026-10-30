# Base3D - Обозначение базы, заданное по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IBases3D ](ibases3d.html) > [IBases3D - свойства ](ibases3d_props.html) |  Scroll [ [ [ ](ibases3d_methods.html "К следующему разделу")](ibases3d_props.html "На уровень выше")](ibases3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibases3d.html)

Тип данных: указатель на интерфейс [IBase3D](ibase3d.html)

Синтаксис Automation:

Base3D = iObject.Base3D( Index ); | Получить свойство ([* ](1.html))  
---|---  
Base3D = iObject.GetBase3D( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Base3D( Index, &Base3D ) | Получить свойство  
---|---  
  
Входные параметры:

Index | VT_BSTR - имя объекта, VT_I4 - индекс объекта.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
