# CreateAttr - Создать атрибут объекта

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](createattriterator.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](choiceattrtypes.html "К предыдущему разделу")  
---|---  
  
[Пример...](createattr_example.html)

Замечание:

Функция устарела, рекомендуется использовать [ksCreateAttr](kscreateattr.html)

Синтаксис:

reference CreateAttr (reference pObj,

Attribute * attr,

double attrID,

char *libname);

Входные параметры:

pObj | \- указатель на объект (группа, вид, отдельный объект), атрибут которого создается. Если pObj = 0, то создается атрибут документа,  
---|---  
attr | \- указатель на структуру параметров табличного атрибута [Attribute](structattribute.html),  
attrID | \- уникальный номер типа атрибута,  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута берется из текущего документа.  
  
Возвращаемое значение:

указатель на атрибут | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
