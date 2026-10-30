# GetKeysInfo - Получить информацию о ключах атрибута

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttributeType ](iattributetype.html) > [IAttributeType - методы ](iattributetype_methods.html) |  Scroll [ [ [ ](iattributetype_setkeysinfo.html "К следующему разделу")](iattributetype_methods.html "На уровень выше")](iattributetype_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattributetype.html)

Синтаксис Automation:

BOOL GetKeysInfo( long* Key1,

long* Key2,

long* Key3,

long* Key4);

Синтаксис COM:

HRESULT GetKeysInfo( long* Key1,

long* Key2,

long* Key3,

long* Key4,

BOOL* Result );

Выходные параметры:

Key1, Key2, Key3, Key4 | \- ключи атрибута.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить информацию о ключах атрибута.

Подразделы:

(отсутствуют)
