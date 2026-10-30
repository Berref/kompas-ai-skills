# SetPlane - Установить секущую плоскость

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Сечение плоскостью (Интерфейсы ksCutByPlaneDefinition, ICutByPlaneDefinition) ](kscutbyplanedefinition.html) > [ICutByPlaneDefinition - методы ](kscutbyplanedefinition_methods.html) |  Scroll [ [ [ ](kscutbysketchdefinition.html "К следующему разделу")](kscutbyplanedefinition_methods.html "На уровень выше")](kscutbyplanedefinition_getplane.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutbyplanedefinition.html)

Синтаксис Automation:

BOOL SetPlane (LPDISPATCH plane);

Синтаксис COM:

BOOL SetPlane (LPENTITY plane);

Входной параметр:

plane | \- указатель на интерфейс секущей плоскости [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
