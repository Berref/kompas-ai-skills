# ksGetAttrValueW - Получить значение ячейки из таблицы атрибута (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](ksgetlibraryattrtypesarray.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](ksgetattrvalue.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksGetAttrValue](ksattributeobject_ksgetattrvalue.html).

Синтаксис:

int ksGetAttrValueW (reference pAttr,

unsigned int rowNumb,

unsigned int columnNumb,

unsigned char *flagVisible,

unsigned char *columnKeys,

void *value,

unsigned int size);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
rowNumb | \- номер строки,  
columnNumb | \- номер колонки,  
size | \- размер выделенной под value памяти.  
  
Выходной параметр:

value | \- указатель на область памяти, куда копируются значения,  
---|---  
flagVisible | \- указатель на массив флагов видимости ячеек строки,  
columnKeys | \- указатель на массив ключей ячеек строки.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Для нетабличного атрибута номер колонки равен нулю.

2\. Указатель на атрибут reference pAttr может быть получен следующими способами:

– с помощью функций итератора [CreateAttrIterator](createattriterator.html), [MoveAttrIterator](moveattriterator.html),

– с помощью функций создания атрибутов [ksCreateAttr](kscreateattr.html) или выбора атрибутов [ChoiceAttr](choiceattr.html).

3\. Для получения размера данных ячейки атрибута может быть использована функция [ksGetSizeAttrValue](ksgetsizeattrvalue.html).

4\. Перед использованием указателей value, flagVisible, columnKeys для каждого указателя должен быть выделен буфер памяти, и его адрес присвоен соответствующей переменной.

5\. При использовании ANSI следует использовать функцию [ksGetAttrValue](ksgetattrvalue.html).

6\. Тип данных, которые находятся в области памяти с указателем value, описывается структурой параметров [ColumnInfoW](structcolumninfow.html) для каждой колонки атрибута.

Подразделы:

(отсутствуют)
