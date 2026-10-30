# SetDepthObject - Установить объект, задающий глубину выдавливания

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Поверхность выдавливания (Интерфейсы ksExtrusionSurfaceDefinition и IExtrusionSurfaceDefinition) ](ksextrusionsurfacedefinition.html) > [ksExtrusionSurfaceDefinition - методы ](ksextrusionsurfacedefinition_methods.html) |  Scroll [ [ [ ](ksextrusionsurfacedefinition_setsideparam.html "К следующему разделу")](ksextrusionsurfacedefinition_methods.html "На уровень выше")](ksextrusionsurfacedefinition_resetdepthobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksextrusionsurfacedefinition.html)

Синтаксис Automation:

VARIANT_BOOL SetDepthObject (VARIANT_BOOL normal, LPDISPATCH obj);

Синтаксис COM:

BOOL SetDepthObject (BOOL normal, LPENTITY obj);

Входные параметры:

normal | \- направление выдавливания: TRUE - совпадает с направлением нормали к плоскости эскиза, FALSE - противоположно направлению нормали к плоскости эскиза.  
---|---  
obj | \- указатель на интерфейс объекта глубины выдавливания [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
