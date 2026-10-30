# ksGetSpcObjForGeomWithLimit - Получить указатель на объект спецификации, подключенный к данному графическому объекту с ограничениями по номеру раздела и типу атрибута

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcobjforgeomwithlimitw.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcobjforgeom.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetspcobjforgeomwithlimit_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcObjForGeomWithLimit](ksspecification_ksgetspcobjforgeomwithlimit.html).

Синтаксис:

reference ksGetSpcObjForGeomWithLimit (char * nameLib,

unsigned int numb,

reference obj,

unsigned char equal,

unsigned char first,

unsigned short section,

double attrTypeNumb);

Входные параметры:

nameLib | \- имя библиотеки стилей спецификации,  
---|---  
numb | \- номер стиля спецификации в библиотеке,  
obj | \- указатель на графический объект или группу объектов (если obj = 0, функция работает с макроэлементом редактирования),  
equal | \- признак вхождения геометрии в состав объекта: 1 - геометрия идентична геометрии объекта спецификации, 0 - геометрия входит в объект спецификации,  
first | \- 1 - первый объект, 0 - следующий объект  
section | \- номер раздела, в котором нужно найти объект (0 - номер не ограничивается),  
attrTypeNumb | \- номер типа атрибута, для которого нужно найти объект (0 - номер не ограничивается).  
  
Возвращаемое значение:

| \- указатель на объект спецификации.  
---|---  
  
Примечания:

1\. Данный метод - только для графических документов.

2\. В настоящий момент метод реализован только для equal = 1.

3\. При использовании Unicode следует использовать функцию [ksGetSpcObjForGeomWithLimitW](ksgetspcobjforgeomwithlimitw.html).

Подразделы:

(отсутствуют)
