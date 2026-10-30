# GetKeysInfo - Выдать информацию о ключах атрибута

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - методы ](iattribute_methods.html) |  Scroll [ [ [ ](iattribute_setcolumnkey.html "К следующему разделу")](iattribute_methods.html "На уровень выше")](iattribute_deleterow.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

Синтаксис Automation:

BOOL GetKeysInfo( long* Key1,

long* Key2,

long* Key3,

long* Key4,

double* Numb );

Синтаксис COM:

HRESULT GetKeysInfo( long* Key1,

long* Key2,

long* Key3,

long* Key4,

double* Numb,

BOOL * Result );

Выходные параметры:

Key1, Key2, Key3, Key4 | \- ключи атрибута,  
---|---  
Numb | \- уникальный номер атрибута.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить информацию о ключах атрибута.

Подразделы:

(отсутствуют)
