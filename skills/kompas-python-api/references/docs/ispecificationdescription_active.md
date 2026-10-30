# Active - Текущее описание

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescription ](ispecificationdescription.html) > [ISpecificationDescription - свойства ](ispecificationdescription_props.html) |  Scroll [ [ [ ](ispecificationdescription_baseobjects.html "К следующему разделу")](ispecificationdescription_props.html "На уровень выше")](ispecificationdescription_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescription.html)

Тип данных: BOOL

Синтаксис Automation:

Active = iObject.Active | Получить свойство ([* ](1.html))  
---|---  
iObject.Active = Active | Установить свойство ([* ](1.html))  
Active = iObject.GetActive() | Получить свойство ([**](2.html))  
iObject.SetActive (Active) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Active (&Active) | Получить свойство  
---|---  
iObject->put_Active (Active) | Установить свойство  
  
Значения свойства:

TRUE | \- описание активно,  
---|---  
FALSE | \- описание неактивно.  
  
Примечание:

1\. Свойство возвращает признак активности описания и позволяет сделать описание активным. Tо есть установить свойство можно только в TRUE.

2\. После изменения параметров оформления метод [Update](ispecificationdescription_update.html) вызывать не требуется.

Подразделы:

(отсутствуют)
