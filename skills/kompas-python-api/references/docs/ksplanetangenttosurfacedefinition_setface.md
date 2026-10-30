# SetFace - Установить указатель на интерфейс цилиндрической или конической грани, к которой требуется построить касательную плоскость

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Касательная плоскость (Интерфейсы ksPlaneTangentToSurfaceDefinition, IPlaneTangentToSurfaceDefinition) ](ksplanetangenttosurfacedefinition.html) > [IPlaneTangentToSurfaceDefinition - методы ](ksplanetangenttosurfacedefinition_methods.html) |  Scroll [ [ [ ](ksplanetangenttosurfacedefinition_setplane.html "К следующему разделу")](ksplanetangenttosurfacedefinition_methods.html "На уровень выше")](ksplanetangenttosurfacedefinition_getsurface.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplanetangenttosurfacedefinition.html)

Синтаксис Automation:

BOOL SetFace (LPDISPATCH face);

Синтаксис COM:

BOOL SetFace (LPENTITY face);

Входной параметр:

plane | \- указатель на интерфейс грани [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
