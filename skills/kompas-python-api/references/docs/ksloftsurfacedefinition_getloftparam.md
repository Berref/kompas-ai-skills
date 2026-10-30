# GetLoftParam - Получить параметры элемента по сечениям

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Поверхность по сечениям(Интерфейсы ksLoftSurfaceDefinition и ILoftSurfaceDefinition) ](ksloftsurfacedefinition.html) > [ksLoftSurfaceDefinition - методы ](ksloftsurfacedefinition_methods.html) |  Scroll [ [ [ ](ksloftsurfacedefinition_getdirectionalline.html "К следующему разделу")](ksloftsurfacedefinition_methods.html "На уровень выше")](ksloftsurfacedefinition_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksloftsurfacedefinition.html)

Синтаксис Automation:

VARIANT_BOOL GetLoftParam (VARIANT_BOOL *closed,

VARIANT_BOOL *flipVertex,

VARIANT_BOOL *autoPath);

Синтаксис COM:

BOOL GetLoftParam (BOOL *closed,

BOOL *flipVertex,

BOOL *autoPath);

Выходные параметры:

closed | \- признак замкнутости траектории: TRUE - траектория замкнута, FALSE - траектория разомкнута,  
---|---  
flipVertex | \- параметр зарезервирован для дальнейшего использования,  
autoPath | \- признак автоматического формирования траектории: TRUE - формировать траекторию автоматически, FALSE - для формирования траектории использовать точки, заданные методом [SetLoftPoint](kssketchdefinition_setloftpoint.html),  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
