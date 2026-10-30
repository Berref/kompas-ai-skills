# Rough3D - Обозначение шероховатости 3D, заданное по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IRoughs3D ](iroughs3d.html) > [IRoughs3D - свойства ](iroughs3d_props.html) |  Scroll [ [ [ ](iroughs3d_methods.html "К следующему разделу")](iroughs3d_props.html "На уровень выше")](iroughs3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iroughs3d.html)

Тип данных: указатель на интерфейс [IRough3D](irough3d.html)

Синтаксис Automation:

Rough3D = iObject.Rough3D( Index ); | Получить свойство ([* ](1.html))  
---|---  
Rough3D = iObject.GetRough3D( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Rough3D( Index, &Rough3D ) | Получить свойство  
---|---  
  
Входные параметры:

Index | VT_BSTR - имя объекта, VT_I4 - индекс объекта.  
---|---  
  
Примечание:

1\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
