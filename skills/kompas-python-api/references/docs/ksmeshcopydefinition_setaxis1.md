# SetAxis1 - Задать первую ось операции

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Копия элементов детали по параллелограммной сетке( Интерфейсы ksMeshCopyDefinition и ICopyMeshDefinition) ](ksmeshcopydefinition.html) > [ICopyMeshDefinition - методы ](ksmeshcopydefinition_methods.html) |  Scroll [ [ [ ](ksmeshcopydefinition_setaxis2.html "К следующему разделу")](ksmeshcopydefinition_methods.html "На уровень выше")](ksmeshcopydefinition_operationarray.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmeshcopydefinition.html)

Синтаксис Automation:

BOOL SetAxis1 (LPDISPATCH entity);

Синтаксис COM:

BOOL SetAxis1 (LPENTITY);

Входные параметры:

entity | \- указатель на интерфейс [ksEntity](ksentity.html) или [IEntity](ksentity.html) (ось или прямолинейное ребро).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Направление сетки можно определить, указывая ребра или оси, вдоль которых строится сетка. Если ось 1 определена, то игнорируется свойство [angle1](ksmeshcopydefinition_angle1.html) (Угол наклона 1-ой оси).

Подразделы:

(отсутствуют)
