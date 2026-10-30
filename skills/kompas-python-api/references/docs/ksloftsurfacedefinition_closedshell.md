# closedShell - Признак замкнутости поверхности

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Поверхность по сечениям(Интерфейсы ksLoftSurfaceDefinition и ILoftSurfaceDefinition) ](ksloftsurfacedefinition.html) > [ksLoftSurfaceDefinition - свойства ](ksloftsurfacedefinition_props.html) |  Scroll [ [ [ ](ksloftsurfacedefinition_methods.html "К следующему разделу")](ksloftsurfacedefinition_props.html "На уровень выше")](ksloftsurfacedefinition_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksloftsurfacedefinition.html)

Тип данных: VARIANT_BOOL

Значения свойства:

TRUE | \- поверхность замкнута,  
---|---  
FALSE | \- поверхность не замкнута.  
  
Синтаксис Automation:

closedShell = iLoft.closedShell | Получить свойство ([* ](1.html))  
---|---  
iLoft.closedShell = closedShell | Установить свойство([* ](1.html))  
closedShell = iLoft.GetClosedShell() | Получить свойство ([**](2.html))  
iLoft.SetClosedShell(closedShell) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

closedShell = iLoft.GetClosedShell() | Получить свойство.  
---|---  
iLoft.SetClosedShell(closedShell) | Установить свойство.  
  
Подразделы:

(отсутствуют)
