# SetPlane - Изменить базовую плоскость эскиза

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Эскиз (Интерфейсы ksSketchDefinition, ISketchDefinition) ](kssketchdefinition.html) > [ISketchDefinition - методы ](kssketchdefinition_methods.html) |  Scroll [ [ [ ](kssketchdefinition_usersetplacement.html "К следующему разделу")](kssketchdefinition_methods.html "На уровень выше")](kssketchdefinition_setlocation.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssketchdefinition.html)

Синтаксис Automation:

BOOL SetPlane (LPDISPATCH plane);

Синтаксис COM:

BOOL SetPlane (LPENTITY plane);

Входной параметр:

plane | \- указатель на интерфейс базовой плоскости эскиза [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
