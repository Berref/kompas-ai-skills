# DepthObject - Объект, задающий глубину выдавливания

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IExtrusion ](iextrusion.html) > [IExtrusion - свойства ](iextrusion_props.html) |  Scroll [ [ [ ](iextrusion_direction.html "К следующему разделу")](iextrusion_props.html "На уровень выше")](iextrusion_depth.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iextrusion.html)

Тип данных: указатель на интерфейс объекта [IModelObject](imodelobject.html)

Синтаксис Automation:

DepthObject = iObject.DepthObject( normal ); | Получить свойство ([* ](1.html))  
---|---  
iObject.DepthObject( normal ) = DepthObject; | Установить свойство ([* ](1.html))  
DepthObject = iObject.GetDepthObject( normal ); | Получить свойство ([**](2.html))  
iObject.SetDepthObject( normal, DepthObject ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DepthObject( normal, &DepthObject ); | Получить свойство  
---|---  
iObject->put_DepthObject( normal, DepthObject ); | Установить свойство  
  
Входные параметры:

normal | TRUE - признак уклона наружу в прямом направлении, FALSE - признак уклона наружу в обратном направлении.  
---|---  
  
Примечание:

1\. Свойство позволяет получать указатель на объект, задающий глубину.

2\. Объект может быть задан, если направление на него совпадает с выбранным направлением (прямым или обратным) операции выдавливания [IExtrusion::Direction](iextrusion_direction.html).

Подразделы:

(отсутствуют)
