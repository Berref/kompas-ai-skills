# SetPlane - Изменить указатель на интерфейс базовой плоскости с указанным номером

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Ось на пересечении плоскостей (Интерфейсы ksAxis2PlanesDefinition, IAxis2PlanesDefinition) ](ksaxis2planesdefinition.html) > [ksAxis2PlanesDefinition - методы ](ksaxis2planesdefinition_methods.html) |  Scroll [ [ [ ](ksaxisoperationsdefinition.html "К следующему разделу")](ksaxis2planesdefinition_methods.html "На уровень выше")](ksaxis2planesdefinition_getplane.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksaxis2planesdefinition.html)

Синтаксис Automation:

BOOL SetPlane(long number, LPDISPATCH plane);

Синтаксис COM:

BOOL SetPlane(long number, LPENTITY plane);

Входные параметры:

plane | \- указатель на интерфейс плоскости [ksEntity](ksentity.html) или [IEntity](ksentity.html),  
---|---  
number | \- номер плоскости (1 или 2).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
