# SetKeysInfo - Установить информацию о ключах атрибута

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - методы ](iattribute_methods.html) |  Scroll [ [ [ ](iattribute_setpassword.html "К следующему разделу")](iattribute_methods.html "На уровень выше")](iattribute_setflagvisible.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

Синтаксис Automation:

BOOL SetKeysInfo( BSTR Password,

long Key1,

long Key2,

long Key3,

long Key4 );

Синтаксис COM:

HRESULT SetKeysInfo( BSTR Password,

long Key1,

long Key2,

long Key3,

long Key4,

BOOL * Result );

Входные параметры:

Password | \- пароль,  
---|---  
Key1, Key2, Key3, Key4 | \- ключи атрибута.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет задать ключи атрибута.

Подразделы:

(отсутствуют)
