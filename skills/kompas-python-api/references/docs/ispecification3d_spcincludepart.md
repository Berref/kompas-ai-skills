# SpcIncludePart - Подключить трехмерный компонент (деталь или подсборку) к объекту спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ISpecification3D ](ispecification3d.html) > [ISpecification3D - методы ](ispecification3d_methods.html) |  Scroll [ [ [ ](kscomponentpositioner.html "К следующему разделу")](ispecification3d_methods.html "На уровень выше")](ispecification3d_getspcobjforgeomwithlimit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecification3d.html)

Синтаксис COM:

BOOL SpcIncludePart (LPPART part,

BOOL fillTexts);

Входные параметры:

part | \- указатель на интерфейс компонента [IPart](kspart.html),  
---|---  
fillTexts | \- признак автоматического заполнения: наименование, обозначение, масса из свойств ksPart: TRUE - автозаполнение включено, FALSE - выключено.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Синтаксис Automation:

[D3SpcIncludePart](ksspecification_d3spcincludepart.html)

Примечание:

Если при подключении компонента присылается флаг fillTexts = true, в объекте спецификации взводится флаг [ISpecificationBaseObject::SyncronizeWithProperties](ispecificationbaseobject_syncronizewithproperties.html).

Подразделы:

(отсутствуют)
