# GetObject- Получить указатель на интерфейс опорного объекта с указанным номером

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Средняя плоскость (Интерфейсы ksPlaneMiddleDefinition, IPlaneMiddleDefinition) ](ksplanemiddledefinition.html) > [IPlaneMiddleDefinition - методы ](ksplanemiddledefinition_methods.html) |  Scroll [ [ [ ](ksplanemiddledefinition_getsurface.html "К следующему разделу")](ksplanemiddledefinition_methods.html "На уровень выше")](ksplanemiddledefinition_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplanemiddledefinition.html)

Синтаксис Automation:

LPDISPATCH GetObject (long Number);

Синтаксис COM:

LPENTITY GetObject (long Number);

Входные параметры:

Number | \- номер объекта (1 или 2).  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksEntity](ksentity.html) или [IEntity](ksentity.html) опорного объекта.  
---|---  
  
Примечание:

Возвращает указатель на интерфейс опорного объекта, на котором построена средняя плоскость. Опорным объектом может быть Ребро, Конструктивная ось, Грань (плоская), Конструктивная плоскость.

Подразделы:

(отсутствуют)
