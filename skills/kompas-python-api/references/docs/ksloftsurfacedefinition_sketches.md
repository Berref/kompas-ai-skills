# Sketches - Получить указатель на интерфейс массива эскизов элемента по сечениям

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Поверхность по сечениям(Интерфейсы ksLoftSurfaceDefinition и ILoftSurfaceDefinition) ](ksloftsurfacedefinition.html) > [ksLoftSurfaceDefinition - методы ](ksloftsurfacedefinition_methods.html) |  Scroll [ [ [ ](ksmoldcavitydefinition.html "К следующему разделу")](ksloftsurfacedefinition_methods.html "На уровень выше")](ksloftsurfacedefinition_setloftparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksloftsurfacedefinition.html)

Синтаксис Automation:

LPDISPATCH Sketches();

Синтаксис COM:

LPENTITYCOLLECTION Sketches();

Возвращаемое значение:

TRUE | \- указатель на интерфейс массива эскизов [ksEntityCollection](ksentitycollection.html) или [IEntityCollection](ksentitycollection.html).  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. В массиве включен контроль, не позволяющий добавить в него нулевой указатель на эскиз.

2\. Эскизы из данного массива используются для построения элемента по сечениям.

Подразделы:

(отсутствуют)
