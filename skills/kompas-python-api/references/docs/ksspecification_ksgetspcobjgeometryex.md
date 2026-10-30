# ksGetSpcObjGeometryEx - Получить деталь или подсборку, подключенную к объекту спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksgetspcobject.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksgetspcobjgeometry.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSpcObjGeometryEx](ksgetspcobjgeometryex.html).

Синтаксис Automation:

long ksGetSpcObjGeometryEx (long spcObj, long geomMode);

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
