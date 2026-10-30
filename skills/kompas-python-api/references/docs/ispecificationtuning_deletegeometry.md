# DeleteGeometry - Режим удаления геометрии при удалении объекта спецификации

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_deletespcobjectondeletegeometry.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_copyspcobjectoncopygeometry.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

DeleteGeometry = iObject.DeleteGeometry | Получить свойство ([* ](1.html))  
---|---  
iObject.DeleteGeometry = DeleteGeometry | Установить свойство ([* ](1.html))  
DeleteGeometry = iObject.GetDeleteGeometry() | Получить свойство ([**](2.html))  
iObject.SetDeleteGeometry (DeleteGeometry) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DeleteGeometry (&DeleteGeometry) | Получить свойство  
---|---  
iObject->put_DeleteGeometry (DeleteGeometry) | Установить свойство  
  
Значения свойства:

TRUE | \- в результате удаления объекта спецификации из чертежа должны удаляться входящие в состав этого объекта графические объекты,  
---|---  
FALSE | \- в результате удаления объекта спецификации из чертежа входящие в состав этого объекта графические объекты удаляться не будут.  
  
Примечание:

Управляет удалением графических объектов, входящих в состав удаляемых объектов спецификации.

Подразделы:

(отсутствуют)
