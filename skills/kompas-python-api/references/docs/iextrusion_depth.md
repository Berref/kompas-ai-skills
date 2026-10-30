# Depth - Глубина выдавливания

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IExtrusion ](iextrusion.html) > [IExtrusion - свойства ](iextrusion_props.html) |  Scroll [ [ [ ](iextrusion_depthobject.html "К следующему разделу")](iextrusion_props.html "На уровень выше")](iextrusion_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iextrusion.html)

Тип данных: double

Синтаксис Automation:

Depth = iObject.Depth( normal ); | Получить свойство ([* ](1.html))  
---|---  
iObject.Depth( normal ) = Depth; | Установить свойство ([* ](1.html))  
Depth = iObject.GetDepth( normal ); | Получить свойство ([**](2.html))  
iObject.SetDepth( normal, Depth ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Depth( normal, &Depth ); | Получить свойство  
---|---  
iObject->put_Depth( normal, Depth ); | Установить свойство  
  
Входные параметры:

normal | TRUE - выдавливание в прямом направлении, FALSE - выдавливание в обратном направлении.  
---|---  
  
Примечание:

Свойство позволяет получить и установить глубину выдавливания.

Подразделы:

(отсутствуют)
