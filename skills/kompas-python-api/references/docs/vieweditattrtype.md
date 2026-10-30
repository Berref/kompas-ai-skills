# ViewEditAttrType - Вывести диалог для просмотра или редактирования типа атрибута

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](events_fncts_common.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](vieweditattr.html "К предыдущему разделу")  
---|---  
  
[Пример...](vieweditattrtype_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksViewEditAttrType](ksattributeobject_ksvieweditattrtype.html).

Синтаксис:

int ViewEditAttrType (char * libname, unsigned int type, double attrId, char * password);

Входные параметры:

libName | \- имя библиотеки типов атрибутов. Если libname = NULL, типы атрибутов берутся из текущего документа,  
---|---  
type | \- режим работы: \- 1 - режим просмотра, 2 - режим редактирования,  
attrId | \- уникальный номер типа атрибута,  
password | \- пароль типа атрибута.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Уникальный номер типа атрибута attrID может быть получен с помощью поля typeid структуры параметров типа атрибута [LibraryAttrTypeParam](structlibraryattrtypeparam.html) или с помощью функции [GetAttrKeysInfo](getattrkeysinfo.html). Тип атрибута должен быть предварительно создан, например, с помощью функции [ksCreateAttrType](kscreateattrtype.html).

Подразделы:

(отсутствуют)
