# GetAttrValue - Получить значение атрибута

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](getsizeattrrow.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](getattrtype.html "К предыдущему разделу")  
---|---  
  
[Пример...](getattrvalue_setattrvalue_getattrrow_setattrrow_example.html)

Замечание. Функция устарела, вместо нее использовать [ksGetAttrValue](ksgetattrvalue.html).

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksGetAttrValue](ksattributeobject_ksgetattrvalue.html).

Синтаксис:

int GetAttrValue (reference pAttr,

unsigned int rowNumb,

unsigned int columnNumb,

unsigned char *flagVisible,

void *value, unsigned int size);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
rowNumb | \- номер строки,  
columnNumb | \- номер колонки,  
flagVisible | \- указатель на массив флагов видимости ячеек строки,  
size | \- размер выделенной под value памяти.  
  
Выходной параметр:

value | \- указатель на область памяти, куда копируются значения.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Тип данных, которые находятся в области памяти с указателем value, описывается структурой параметров [ColumnInfo](structcolumninfo.html) для каждой колонки атрибута.

Подразделы:

(отсутствуют)
