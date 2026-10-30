# GetAxis2 - Получить вторую ось операции

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Копия элементов детали по параллелограммной сетке( Интерфейсы ksMeshCopyDefinition и ICopyMeshDefinition) ](ksmeshcopydefinition.html) > [ICopyMeshDefinition - методы ](ksmeshcopydefinition_methods.html) |  Scroll [ [ [ ](ksmeshcopydefinition_getcopyparamalongaxis.html "К следующему разделу")](ksmeshcopydefinition_methods.html "На уровень выше")](ksmeshcopydefinition_getaxis1.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmeshcopydefinition.html)

Синтаксис Automation:

LPDISPATCH GetAxis2();

Синтаксис COM:

LPENTITY GetAxis2();

Возвращаемое значение:

указатель на интерфейс [ksEntity](ksentity.html) или[ IEntity](ksentity.html). | \- в случае успешного завершения,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание:

Направление сетки можно определить, указывая ребра или оси, вдоль которых строится сетка. Если ось 2 определена, то игнорируется свойство [angle2](ksmeshcopydefinition_angle2.html) (Угол наклона 2-ой оси).

Подразделы:

(отсутствуют)
