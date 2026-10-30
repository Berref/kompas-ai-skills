# closedShell - Признак замкнутости поверхности

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Поверхность вращения (Интерфейсы ksRotatedSurfaceDefinition и IRotatedSurfaceDefinition) ](ksrotatedsurfacedefinition.html) > [ksRotatedSurfaceDefinition - свойства ](ksrotatedsurfacedefinition_props.html) |  Scroll [ [ [ ](ksrotatedsurfacedefinition_directiontype.html "К следующему разделу")](ksrotatedsurfacedefinition_props.html "На уровень выше")](ksrotatedsurfacedefinition_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrotatedsurfacedefinition.html)

Тип данных: VARIANT_BOOL

Значения свойства:

TRUE | \- поверхность замкнута,  
---|---  
FALSE | \- поверхность не замкнута.  
  
Синтаксис Automation:

closedShell = iRotated.closedShell | Получить свойство ([* ](1.html))  
---|---  
iRotated.closedShell = closedShell | Установить свойство([* ](1.html))  
closedShell = iRotated.GetClosedShell() | Получить свойство ([**](2.html))  
iRotated.SetClosedShell(closedShell) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

closedShell = iRotated.GetClosedShell() | Получить свойство.  
---|---  
iRotated.SetClosedShell(closedShell) | Установить свойство.  
  
Подразделы:

(отсутствуют)
