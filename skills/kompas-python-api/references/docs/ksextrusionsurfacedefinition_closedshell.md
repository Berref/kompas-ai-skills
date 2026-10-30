# closedShell - Признак замкнутости поверхности

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Поверхность выдавливания (Интерфейсы ksExtrusionSurfaceDefinition и IExtrusionSurfaceDefinition) ](ksextrusionsurfacedefinition.html) > [ksExtrusionSurfaceDefinition - свойства ](ksextrusionsurfacedefinition_props.html) |  Scroll [ [ [ ](ksextrusionsurfacedefinition_directiontype.html "К следующему разделу")](ksextrusionsurfacedefinition_props.html "На уровень выше")](ksextrusionsurfacedefinition_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksextrusionsurfacedefinition.html)

Тип данных: VARIANT_BOOL

Значения свойства:

TRUE | \- поверхность замкнута,  
---|---  
FALSE | \- поверхность не замкнута.  
  
Синтаксис Automation:

closedShell = iExtrusion.closedShell | Получить свойство ([* ](1.html))  
---|---  
iExtrusion.closedShell = closedShell | Установить свойство([* ](1.html))  
closedShell = iExtrusion.GetClosedShell() | Получить свойство ([**](2.html))  
iExtrusion.SetClosedShell(closedShell) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

closedShell = iExtrusion.GetClosedShell() | Получить свойство.  
---|---  
iExtrusion.SetClosedShell(closedShell) | Установить свойство.  
  
Подразделы:

(отсутствуют)
