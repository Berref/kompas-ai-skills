# D3GetSpcObjGeometry - Получить деталь или подсборку, подключенную к объекту спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ISpecification3D ](ispecification3d.html) > [ISpecification3D - методы ](ispecification3d_methods.html) |  Scroll [ [ [ ](ispecification3d_getspcobjforgeomwithlimit.html "К следующему разделу")](ispecification3d_methods.html "На уровень выше")](ispecification3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecification3d.html)

Аналог данного метода при использовании API экспортных функций - [ksD3GetSpcObjGeometry](ksd3getspcobjgeometry.html).

Синтаксис Automation:

LPPART D3GetSpcObjGeometry(long spcObj);

Входные параметры:

spcObj | \- указатель на объект спецификации.  
---|---  
  
Возвращаемое значение:

Указатель на интерфейс [IPart](kspart.html) | \- в случае успешного завершения,  
---|---  
0 | \- если деталь не подключена или в случае ошибки.  
  
Подразделы:

(отсутствуют)
