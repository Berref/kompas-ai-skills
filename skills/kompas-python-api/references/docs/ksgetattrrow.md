# ksGetAttrRow - Получить строку атрибута

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](ksgetattrroww.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](ksdeleteattr3dw.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при использовании Automation - метод [ksAttributeObject::ksGetAttrRow](ksattributeobject_ksgetattrrow.html).

Синтаксис:

int ksGetAttrRow (reference pAttr,

unsigned int rowNumb,

unsigned char * flagVisible,

unsigned char * columnKeys,

void * value,

unsigned int size );

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
rowNumb | \- номер строки,  
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

1\. Указатель на атрибут reference pAttr может быть получен следующими способами:

– с помощью функций итератора [CreateAttrIterator](createattriterator.html), [MoveAttrIterator](moveattriterator.html),

– с помощью функций создания атрибутов [ksCreateAttr](kscreateattr.html) или выбора атрибутов [ChoiceAttr](choiceattr.html).

2\. Перед использованием указателя flagVisible должен быть выделен буфер памяти, например, char buffer[MAX_TEXT_LENGTH], и его адрес присвоен переменной flagVisible.

3\. Перед использованием указателя columnKeys должен быть выделен буфер памяти, и его адрес присвоен переменной columnKeys.

4\. Перед использованием указателя value должен быть выделен буфер памяти, например, char buffer[MAX_TEXT_LENGTH], и его адрес присвоен переменной value.

5\. Для получения размера данных ячейки атрибута может быть использована функция [ksGetSizeAttrValue](ksgetsizeattrvalue.html).

6\. При использовании Unicode следует использовать функцию [ksGetAttrRowW](ksgetattrroww.html).

7\. Тип данных, которые находятся в области памяти с указателем value, описывается структурой параметров [ColumnInfo](structcolumninfo.html) для каждой колонки атрибута.

Подразделы:

(отсутствуют)
