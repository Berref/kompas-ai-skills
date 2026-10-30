# Hidden - Состояние видимости объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [3D-объект ](bc2229904.html) > [Интерфейс IModelObject ](imodelobject.html) > [IModelObject - свойства ](imodelobject_props.html) |  Scroll [ [ [ ](imodelobject_modelobjecttype.html "К следующему разделу")](imodelobject_props.html "На уровень выше")](imodelobject_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imodelobject.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- объект скрыт,  
---|---  
FALSE | \- объект показан.  
  
Синтаксис Automation:

Hidden = iObject.Hidden | Получить свойство([* ](1.html))  
---|---  
iObject.Hidden = Hidden | Установить свойство ([* ](1.html))  
Hidden = iObject.GetHidden( ) | Получить свойство ([**](2.html))  
iObject.SetHidden ( Hidden ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Hidden ( &Hidden ) | Получить свойство  
---|---  
iObject->put_Hidden ( Hidden ) | Установить свойство  
  
Примечание:

1\. Позволяет получить и установить состояние видимости объекта.

2\. Свойство вступает в силу после вызова метода [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
