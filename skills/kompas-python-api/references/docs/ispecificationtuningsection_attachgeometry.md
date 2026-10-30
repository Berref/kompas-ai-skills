# AttachGeometry - Подключать геометрию

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuningSection ](ispecificationtuningsection.html) > [ISpecificationTuningSection - свойства ](ispecificationtuningsection_props.html) |  Scroll [ [ [ ](ispecificationtuningsection_firstonsheet.html "К следующему разделу")](ispecificationtuningsection_props.html "На уровень выше")](ispecificationtuningsection_additionalblocks.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuningsection.html)

Тип данных: BOOL

Синтаксис Automation:

AttachGeometry = iObject.AttachGeometry | Получить свойство ([* ](1.html))  
---|---  
iObject.AttachGeometry = AttachGeometry | Установить свойство ([* ](1.html))  
AttachGeometry = iObject.GetAttachGeometry() | Получить свойство ([**](2.html))  
iObject.SetAttachGeometry (AttachGeometry) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_AttachGeometry (&AttachGeometry) | Получить свойство  
---|---  
iObject->put_AttachGeometry (AttachGeometry) | Установить свойство  
  
Значения свойства:

TRUE | \- объектам раздела можно поставить в соответствие геометрические объекты графического документа,  
---|---  
FALSE | \- объектам раздела нельзя поставить в соответствие геометрические объекты графического документа.  
  
Примечание:

Позволяет включать и отключать подключение геометрии к объектам раздела.

Подразделы:

(отсутствуют)
