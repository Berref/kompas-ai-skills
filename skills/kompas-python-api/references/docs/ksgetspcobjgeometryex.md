# ksGetSpcObjGeometryEx - Получить графический объект, подключенный к объекту спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcobjectsummarycount.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcobjgeometry.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcObjGeometryEx](ksspecification_ksgetspcobjgeometryex.html).

Синтаксис:

reference ksGetSpcObjGeometryEx (reference spcObj, int geomMode);

Входные параметры:

spcObj | \- указатель на объект спецификации,  
---|---  
geomMode | 0 - только геометрия; 1 - только линии выноски; 2 - геометрия и линии выноски.  
  
Возвращаемое значение:

указатель на группу | \- в случае успешного завершения,  
---|---  
0 | \- в случае, если геометрия не подключена или в случае ошибки.  
  
Подразделы:

(отсутствуют)
