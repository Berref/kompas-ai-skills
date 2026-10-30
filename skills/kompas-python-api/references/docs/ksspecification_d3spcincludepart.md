# D3SpcIncludePart - Добавить или изменить трехмерный компонент (деталь или подсборку) в объекте спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_getspcobjectcolumntextex.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_d3getspcobjgeometry.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [D3SpcIncludePart](d3spcincludepart.html).

Синтаксис Automation:

BOOL D3SpcIncludePart (LPDISPATCH part, VARIANT_BOOL fillTexts);

Входные параметры:

part | \- указатель на интерфейс компонента [ksPart](kspart.html),  
---|---  
fillTexts | \- признак автоматического заполнения: наименование, обозначение, масса из свойств ksPart: TRUE - автозаполнение включено, FALSE - выключено.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Синтаксис COM:

[ISpecification3D::SpcIncludePart](ispecification3d_spcincludepart.html)

Примечание:

Если при подключении компонента присылается флаг fillTexts = true, в объекте спецификации взводится флаг [ISpecificationBaseObject::SyncronizeWithProperties](ispecificationbaseobject_syncronizewithproperties.html).

Подразделы:

(отсутствуют)
