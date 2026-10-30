# ShowOnSheet - Показывать на листе

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescription ](ispecificationdescription.html) > [ISpecificationDescription - свойства ](ispecificationdescription_props.html) |  Scroll [ [ [ ](ispecificationdescription_showexcludedobjects.html "К следующему разделу")](ispecificationdescription_props.html "На уровень выше")](ispecificationdescription_showallobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescription.html)

Тип данных: BOOL

Синтаксис Automation:

ShowOnSheet = iObject.ShowOnSheet | Получить свойство ([* ](1.html))  
---|---  
iObject.ShowOnSheet = ShowOnSheet | Установить свойство ([* ](1.html))  
ShowOnSheet = iObject.GetShowOnSheet() | Получить свойство ([**](2.html))  
iObject.SetShowOnSheet (ShowOnSheet) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ShowOnSheet (&ShowOnSheet) | Получить свойство  
---|---  
iObject->put_ShowOnSheet (ShowOnSheet) | Установить свойство  
  
Значения свойства:

TRUE | \- описание отображается на чертеже,  
---|---  
FALSE | \- описание не отображается на чертеже.  
  
Примечание:

1\. Свойство позволяет отобразить или скрыть спецификацию в чертеже.

2\. Свойство работает только в чертеже.

Подразделы:

(отсутствуют)
