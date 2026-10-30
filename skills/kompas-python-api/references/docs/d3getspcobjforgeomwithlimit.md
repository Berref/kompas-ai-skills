# D3GetSpcObjForGeomWithLimit - Получить указатель на объект спецификации, подключенный к трехмерному компоненту (детали или подсборке) с ограничениями по номеру раздела и типу атрибута

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](d3spcincludepart.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](createspciteratorw.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при при использовании Automation - метод [D3GetSpcObjForGeomWithLimit](ksspecification_d3getspcobjforgeomwithlimit.html).

Синтаксис:

long D3GetSpcObjForGeomWithLimit (BSTR nameLib,

long numb,

LPDISPATCH part,

short first,

short section,

double attrTypeNumb);

Входные параметры:

nameLib | \- имя библиотеки стилей спецификации,  
---|---  
numb | \- номер стиля спецификации в библиотеке,  
part | \- указатель на интерфейс добавляемого компонента [ksPart](kspart.html),  
first | \- 1 -первый объект, 0 - следующий объект,  
section | \- номер раздела, в котором нужно найти объект (0 - номер не ограничивается),  
attrTypeNumb | \- номер типа атрибута, для которого нужно найти объект (0 - номер не ограничивается).  
  
Возвращаемое значение:

| \- указатель на объект спецификации.  
---|---  
  
Подразделы:

(отсутствуют)
