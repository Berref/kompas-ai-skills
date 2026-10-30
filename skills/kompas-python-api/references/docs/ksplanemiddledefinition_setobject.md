# SetObject - Установить указатель на интерфейс опорного объекта с указанным номером

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Средняя плоскость (Интерфейсы ksPlaneMiddleDefinition, IPlaneMiddleDefinition) ](ksplanemiddledefinition.html) > [IPlaneMiddleDefinition - методы ](ksplanemiddledefinition_methods.html) |  Scroll [ [ [ ](ksplaneoffsetdefinition.html "К следующему разделу")](ksplanemiddledefinition_methods.html "На уровень выше")](ksplanemiddledefinition_getsurface.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplanemiddledefinition.html)

Синтаксис Automation:

VARIANT_BOOL SetObject (long Number, LPDISPATCH Val);

Синтаксис COM:

BOOL SetObject (long Number, LPENTITY Val);

Входные параметры:

Number | \- номер объекта (1 или 2).  
---|---  
Val | \- указатель на интерфейс [ksEntity](ksentity.html) или [IEntity](ksentity.html) опорного объекта.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Позволяет задать опорный объект, на котором будет построена средняя плоскость. Опорным объектом может быть Ребро, Конструктивная ось, Грань (плоская), Конструктивная плоскость.

Подразделы:

(отсутствуют)
