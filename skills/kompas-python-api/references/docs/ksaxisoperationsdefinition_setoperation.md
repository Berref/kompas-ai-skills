# SetOperation - Задать базовый формообразующий элемент

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Ось формообразующего элемента (Интерфейсы ksAxisOperationsDefinition, IAxisOperationsDefinition) ](ksaxisoperationsdefinition.html) > [ksAxisOperationsDefinition - методы ](ksaxisoperationsdefinition_methods.html) |  Scroll [ [ [ ](ksaxisconefacedefinition.html "К следующему разделу")](ksaxisoperationsdefinition_methods.html "На уровень выше")](ksaxisoperationsdefinition_getoperation.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksaxisoperationsdefinition.html)

Синтаксис Automation:

BOOL SetOperation (LPDISPATCH operation);

Синтаксис COM:

BOOL SetOperation (LPENTITY operation);

Входной параметр:

operation | \- указатель на интерфейс базового формообразующего элемента [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
