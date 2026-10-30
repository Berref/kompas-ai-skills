# SetStringRegularValidator - Установить валидатор регулярного выражения для строкового редактора

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyEdit ](ipropertyedit.html) > [IPropertyEdit - методы ](ipropertyedit_methods.html) |  Scroll [ [ [ ](ipropertyedit_setvaluerange.html "К следующему разделу")](ipropertyedit_methods.html "На уровень выше")](ipropertyedit_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyedit.html)

Синтаксис Automation:

BOOL SetStringRegularValidator( BSTR InputMask, BSTR ValidateMask, BSTR ErrorMessage, BSTR EmptyStringErrorMessage );

Синтаксис COM:

HRESULT SetStringRegularValidator( BSTR InputMask, BSTR ValidateMask, BSTR ErrorMessage, BSTR EmptyStringErrorMessage, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

InputMask | \- маска ввода,  
---|---  
ValidateMask | \- маска допустимых символов,  
ErrorMessage | \- сообщение об ошибке,  
EmptyStringErrorMessage | \- сообщение для пустой строки.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
