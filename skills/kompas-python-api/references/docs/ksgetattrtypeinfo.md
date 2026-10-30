# ksGetAttrTypeInfo - Выдать информацию о типе атрибута

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](ksgetattrtypeinfow.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](ksgetattrtype.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

int LIB_FUNC ksGetAttrТypeInfo (reference pAttr,

double * numb,

char * attrTypeName,

unsigned int attrTypeNameSize,

char * attrTypeFileName,

unsigned int attrTypeFileNameSize,

char * attrTypePathInFile,

unsigned int attrTypePathInFileSize);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
attrTypeNameSize | \- размер буферa имени типа атрибута,  
attrTypeFileNameSize | \- размер буферa имени файла с описанием типа атрибута,  
attrTypePathInFileSize | \- размер буферa для пути к описанию типа атрибута внутри библиотеки типов.  
  
Выходные параметры:

numb | \- номер типа атрибута,  
---|---  
attrTypeName | \- имя типа атрибута,  
attrTypeFileName | \- имя файла, в котором описан тип атрибута,  
attrTypePathInFile | \- путь к описанию типа атрибута внутри библиотеки типов.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Если присылается NULL, соответствующее поле не заполняется.

Подразделы:

(отсутствуют)
