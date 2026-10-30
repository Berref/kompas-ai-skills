# Ломаная ( Интерфейсы ksPolyLineDefinition и IPolygonalLineDefinition)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы пространственных кривых ](int_pr_curve.html) |  Scroll [ [ [ ](kspolylinedefinition_props.html "К следующему разделу")](int_pr_curve.html "На уровень выше")](kssplinedefinition_writetofile.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров ломаной.

ksPolyLineDefinition | \- интерфейс Automation  
---|---  
IPolygonalLineDefinition | \- интерфейс COM  
  
Примечание:

Интерфейс может быть получен от интерфейса [ksEntity](ksentity.html) или [IEntity](ksentity.html) с помощью метода [ksEntity::GetDefinition](ksentity_getdefinition.html) или [IEntity::GetDefinition](ksentity_getdefinition.html) и последующим приведением объекта типа IDispatch или IUnknown к интерфейсу типа ksPolyLineDefinition или IPolygonalLineDefinition соответственно.

Подразделы:

[IPolygonalLineDefinition - свойства ](kspolylinedefinition_props.html)

[IPolygonalLineDefinition - методы ](kspolylinedefinition_methods.html)
