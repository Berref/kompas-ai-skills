# DraftOutward - Признак уклона внутрь

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IExtrusion ](iextrusion.html) > [IExtrusion - свойства ](iextrusion_props.html) |  Scroll [ [ [ ](iextrusion_draftvalue.html "К следующему разделу")](iextrusion_props.html "На уровень выше")](iextrusion_direction.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iextrusion.html)

Тип данных: bool

Синтаксис Automation:

DraftOutward = iObject.DraftOutward( normal ); | Получить свойство ([* ](1.html))  
---|---  
iObject.DraftOutward( normal ) = DraftOutward; | Установить свойство ([* ](1.html))  
DraftOutward = iObject.GetDraftOutward( normal ); | Получить свойство ([**](2.html))  
iObject.SetDraftOutward( normal, DraftOutward ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DraftOutward( normal, &DraftOutward ); | Получить свойство  
---|---  
iObject->put_DraftOutward( normal, DraftOutward ); | Установить свойство  
  
Входные параметры:

normal | TRUE - признак уклона наружу в прямом направлении, FALSE - признак уклона наружу в обратном направлении.  
---|---  
  
Примечание:

Свойство позволяет получить и установить признак уклона внутрь.

Подразделы:

(отсутствуют)
