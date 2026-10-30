# DeleteSpcObjectOnDeleteGeometry - Режим удаления спецификации при удалении геометрии

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_disableemptystring.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_deletegeometry.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- в результате удаления графического объекта из чертежа должны удаляться соответствующие объекты спецификации,  
---|---  
FALSE | \- в результате удаления графического объекта из чертежа соответствующие объекты спецификации удаляться не будут.  
  
Синтаксис Automation:

DeleteSpcObjectOnDeleteGeometry = iObject.DeleteSpcObjectOnDeleteGeometry | Получить свойство ([* ](1.html))  
---|---  
iObject.DeleteSpcObjectOnDeleteGeometry = DeleteSpcObjectOnDeleteGeometry | Установить свойство ([* ](1.html))  
DeleteSpcObjectOnDeleteGeometry = iObject.GetDeleteSpcObjectOnDeleteGeometry() | Получить свойство ([**](2.html))  
iObject.SetDeleteSpcObjectOnDeleteGeometry (DeleteSpcObjectOnDeleteGeometry) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DeleteSpcObjectOnDeleteGeometry (&DeleteSpcObjectOnDeleteGeometry) | Получить свойство  
---|---  
iObject->put_DeleteSpcObjectOnDeleteGeometry (DeleteSpcObjectOnDeleteGeometry) | Установить свойство  
  
Примечание:

Управляет удалением объектов спецификации при удалении графических объектов.

Подразделы:

(отсутствуют)
