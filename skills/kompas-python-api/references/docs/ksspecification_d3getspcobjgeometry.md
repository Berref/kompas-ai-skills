# D3GetSpcObjGeometry - Получить деталь или подсборку, подключенную к объекту спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_d3spcincludepart.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_d3getspcobjforgeomwithlimit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksD3GetSpcObjGeometry](ksd3getspcobjgeometry.html).

Синтаксис Automation:

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
