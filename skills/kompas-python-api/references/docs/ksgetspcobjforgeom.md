# ksGetSpcObjForGeom - Получить указатель объекта СП по геометрии для текущего графического документа

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcobjforgeomwithlimit.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcobjectsummarycounttext.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksspcobjectcreate_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcObjForGeom](ksspecification_ksgetspcobjforgeom.html).

Синтаксис:

reference ksGetSpcObjForGeom (char * nameLib,

unsigned int numb,

reference obj,

unsigned char equal,

unsigned char first);

Входные параметры:

nameLib | \- имя библиотеки стилей спецификации,  
---|---  
numb | \- номер стиля спецификации в библиотеке,  
obj | \- указатель на графический объект или группу объектов (0 - макроэлемент редактирования),  
equal | \- признак вхождения геометрии в состав объекта: 1 - геометрия идентична геометрии объекта спецификации, 0 - геометрия входит в объект спецификации,  
first | \- 1 - первый объект, 0 - следующий объект.  
  
Возвращаемое значение:

| \- указатель на объект спецификации.  
---|---  
  
Примечания:

1\. Данный метод - только для графических документов.

2\. В настоящий момент метод реализован только для equal = 1.

Подразделы:

(отсутствуют)
