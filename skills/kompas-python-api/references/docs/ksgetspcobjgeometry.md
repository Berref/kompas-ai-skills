# ksGetSpcObjGeometry - Получить деталь или подсборку, подключенную к объекту спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcobjgeometryex.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcobjforgeomwithlimitw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcObjGeometry](ksspecification_ksgetspcobjgeometry.html).

Синтаксис:

reference ksGetSpcObjGeometry (reference spcObj);

Входные параметры:

spcObj | \- указатель на объект спецификации.  
---|---  
  
Возвращаемое значение:

указатель на группу | \- в случае успешного завершения,  
---|---  
0 | \- в случае если геометрия не подключена или в случае ошибки.  
  
Примечания:

Функция устарела, рекомендуется вместо нее использовать функцию [ksGetSpcObjGeometryEx](ksgetspcobjgeometryex.html).

Подразделы:

(отсутствуют)
