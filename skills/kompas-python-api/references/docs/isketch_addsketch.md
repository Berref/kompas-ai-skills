# AddSketch - Создать эскиз из уже имеющегося в заданной плоскости

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Эскиз ](bc2287727.html) > [Интерфейс ISketch ](isketch.html) > [ISketch - методы ](isketch_methods.html) |  Scroll [ [ [ ](isketch_beginedit.html "К следующему разделу")](isketch_methods.html "На уровень выше")](isketch_addprojectionof.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isketch.html)

Синтаксис Automation:

BOOL AddSketch( IModelObject * Sketch, IModelObject * Plane );

Синтаксис COM:

HRESULT AddSketch( IModelObject * Sketch, IModelObject * Plane, BOOL * Result );

Входные параметры:

Sketch | \- указатель на эскиз,  
---|---  
Plane | \- указатель на плоскость.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
