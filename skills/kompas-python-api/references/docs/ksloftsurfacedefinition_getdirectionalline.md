# GetDirectionalLine - Получить направляющую линию. Эскиз в котором лежит кривая

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Поверхность по сечениям(Интерфейсы ksLoftSurfaceDefinition и ILoftSurfaceDefinition) ](ksloftsurfacedefinition.html) > [ksLoftSurfaceDefinition - методы ](ksloftsurfacedefinition_methods.html) |  Scroll [ [ [ ](ksloftsurfacedefinition_setdirectionalline.html "К следующему разделу")](ksloftsurfacedefinition_methods.html "На уровень выше")](ksloftsurfacedefinition_getloftparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksloftsurfacedefinition.html)

Синтаксис Automation:

LPDISPATCH GetDirectionalLine();

Синтаксис COM:

LPENTITY GetDirectionalLine();

Возвращаемое значение:

TRUE | \- указатель на интерфейс [ksEntity](ksentity.html) или [Ientity](ksentity.html).  
---|---  
  
Примечание:

Если задана направляющая, то признак замкнутости траектории устанавливается автоматически, исходя из замкнутости направляющей.

Подразделы:

(отсутствуют)
