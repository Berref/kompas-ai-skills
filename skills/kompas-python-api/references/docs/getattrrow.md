# GetAttrRow - Получить строку атрибута

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](getattrtabinfo.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](getattrkeysinfo.html "К предыдущему разделу")  
---|---  
  
[Пример...](getattrvalue_setattrvalue_getattrrow_setattrrow_example.html)

Синтаксис:

int GetAttrRow (reference pAttr,

unsigned int rowNumb,

unsigned char *flagVisible,

void *value,

unsigned int size);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
rowNumb | \- номер строки,  
size | \- размер выделенной под value памяти.  
  
Выходной параметр:

value | \- указатель на область памяти, куда копируются значения,  
---|---  
flagVisible | \- указатель на массив флагов видимости ячеек строки.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Функция устарела, рекомендуется вместо нее использовать функцию [ksGetAttrRow](ksgetattrrow.html).

2\. Указатель на атрибут reference pAttr может быть получен следующими способами:

– с помощью функций итератора [CreateAttrIterator](createattriterator.html), [MoveAttrIterator](moveattriterator.html),

– с помощью функций создания атрибутов [ksCreateAttr](kscreateattr.html) или выбора атрибутов [ChoiceAttr](choiceattr.html).

3\. Перед использованием указателя flagVisible должен быть выделен буфер памяти, например, char buffer[MAX_TEXT_LENGTH], и его адрес присвоен переменной flagVisible.

4\. Перед использованием указателя value должен быть выделен буфер памяти, например, char buffer[MAX_TEXT_LENGTH], и его адрес присвоен переменной value.

5\. Для получения размера данных строки атрибута может быть использована функция [ksGetSizeAttrRow](ksgetsizeattrrow.html).

6\. Тип данных, которые находятся в области памяти с указателем value, описывается структурой параметров [ColumnInfo](structcolumninfo.html) для каждой колонки атрибута.

Подразделы:

(отсутствуют)
