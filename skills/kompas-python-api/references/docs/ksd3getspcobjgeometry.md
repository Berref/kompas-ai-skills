# ksD3GetSpcObjGeometry - Получить деталь или подсборку, подключенную к объекту спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksdeletespcdescription.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksaddspcdescriptionw.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при при использовании Automation - метод [ksD3GetSpcObjGeometry](ksspecification_d3getspcobjgeometry.html).

Синтаксис:

LPDISPATCH D3GetSpcObjGeometry (long spcObj);

Входные параметры:

spcObj | \- указатель на объект спецификации.  
---|---  
  
Возвращаемое значение:

Указатель на интерфейс [ksPart](kspart.html) | \- в случае успешного завершения,  
---|---  
0 | \- если деталь не подключена или в случае ошибки.  
  
Подразделы:

(отсутствуют)
