# SetPassword - Установить новый пароль на изменение данных атрибута

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttributeType ](iattributetype.html) > [IAttributeType - методы ](iattributetype_methods.html) |  Scroll [ [ [ ](iattributetype_update.html "К следующему разделу")](iattributetype_methods.html "На уровень выше")](iattributetype_setkeysinfo.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattributetype.html)

Синтаксис Automation:

BOOL SetPassword( BSTR OldPassword,

BSTR NewPassword );

Синтаксис COM:

HRESULT SetPassword( BSTR OldPassword,

BSTR NewPassword,

BOOL * Result );

Входные параметры:

OldPassword | \- старый пароль,  
---|---  
NewPassword | \- новый пароль.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить новый пароль на изменение данных атрибута.

Подразделы:

(отсутствуют)
