# CurrentObject - Текущий объект спецификации (выделенный или редактируемый в таблице спецификации)

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescription ](ispecificationdescription.html) > [ISpecificationDescription - свойства ](ispecificationdescription_props.html) |  Scroll [ [ [ ](ispecificationdescription_delegatemode.html "К следующему разделу")](ispecificationdescription_props.html "На уровень выше")](ispecificationdescription_commentobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescription.html)

Тип данных: указатель на интерфейс [ISpecificationObject](ispecificationobject.html) объекта спецификации.

Синтаксис Automation:

CurrentObject = iObject.CurrentObject | Получить свойство ([* ](1.html))  
---|---  
iObject.CurrentObject = CurrentObject | Установить свойство ([* ](1.html))  
CurrentObject = iObject.GetCurrentObject() | Получить свойство ([**](2.html))  
iObject.SetCurrentObject (CurrentObject) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CurrentObject (&CurrentObject) | Получить свойство  
---|---  
iObject->put_CurrentObject (CurrentObject) | Установить свойство  
  
Примечание:

1\. С помощью данного свойства можно получить и установить текущий объект спецификации.

2\. В графическом документе или документе-модели метод работает, если открыто окно спецификации в подчиненном режиме.

Подразделы:

(отсутствуют)
