# DraftValue - Угол наклона

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IExtrusion ](iextrusion.html) > [IExtrusion - свойства ](iextrusion_props.html) |  Scroll [ [ [ ](iextrusion_extrusiontype.html "К следующему разделу")](iextrusion_props.html "На уровень выше")](iextrusion_draftoutward.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iextrusion.html)

Тип данных: double

Синтаксис Automation:

DraftValue = iObject.DraftValue( normal ); | Получить свойство ([* ](1.html))  
---|---  
iObject.DraftValue( normal ) = DraftValue; | Установить свойство ([* ](1.html))  
DraftValue = iObject.GetDraftValue( normal ); | Получить свойство ([**](2.html))  
iObject.SetDraftValue( normal, DraftValue ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DraftValue( normal, &DraftValue ); | Получить свойство  
---|---  
iObject->put_DraftValue( normal, DraftValue ); | Установить свойство  
  
Входные параметры:

normal | TRUE - угол наклона в прямом направлении, FALSE - угол наклона в обратном направлении.  
---|---  
  
Примечание:

Свойство позволяет получить и установить угол наклона.

Подразделы:

(отсутствуют)
