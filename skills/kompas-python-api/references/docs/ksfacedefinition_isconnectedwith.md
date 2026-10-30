# IsConnectedWith - Проверить, связаны ли грани

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Грань (Интерфейсы ksFaceDefinition, IFaceDefinition) ](ksfacedefinition.html) > [IFaceDefinition - методы ](ksfacedefinition_methods.html) |  Scroll [ [ [ ](ksfacedefinition_iscylinder.html "К следующему разделу")](ksfacedefinition_methods.html "На уровень выше")](ksfacedefinition_iscone.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksfacedefinition.html)

Синтаксис Automation:

BOOL IsConnectedWith (LPDISPATCH other);

Синтаксис COM:

BOOL IsConnectedWith (LPFACEDEFINITION other);

Входные параметры:

| \- указатель на интерфейс [ksFaceDefinition](ksfacedefinition.html) или [IFaceDefinition](ksfacedefinition.html) другой грани.  
---|---  
  
Возвращаемое значение:

TRUE | \- если грани связаны,  
---|---  
FALSE | \- если грани не связаны.  
  
Подразделы:

(отсутствуют)
