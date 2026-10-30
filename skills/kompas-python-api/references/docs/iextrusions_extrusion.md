# Extrusion - Операция выдавливания, заданная по индексу или ссылке

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IExtrusions ](iextrusions.html) > [IExtrusions - свойства ](iextrusions_props.html) |  Scroll [ [ [ ](iextrusions_methods.html "К следующему разделу")](iextrusions_props.html "На уровень выше")](iextrusions_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iextrusions.html)

Тип данных: указатель на интерфейс [IExtrusion](iextrusion.html)

Синтаксис Automation:

Extrusion = iObject.Extrusion( index ) | Получить свойство ([* ](1.html))  
---|---  
Extrusion = iObject.GetExtrusion( index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Extrusion( index, &Extrusion ) | Получить свойство  
---|---  
  
Входные параметры:

VARIANT index | \- индекс операции выдавливания.  
---|---  
  
Примечание:

В качестве индекса может использоваться:

•индекс объекта в коллекции,

•ссылка на объект (reference).

Подразделы:

(отсутствуют)
