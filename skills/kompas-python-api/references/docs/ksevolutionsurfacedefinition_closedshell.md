# closedShel - Признак замкнутости поверхности

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Кинематическая поверхность (Интерфейсы ksEvolutionSurfaceDefinition и IEvolutionSurfaceDefinition) ](ksevolutionsurfacedefinition.html) > [ksEvolutionSurfaceDefinition - свойства ](ksevolutionsurfacedefinition_props.html) |  Scroll [ [ [ ](ksevolutionsurfacedefinition_sketchshifttype.html "К следующему разделу")](ksevolutionsurfacedefinition_props.html "На уровень выше")](ksevolutionsurfacedefinition_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksevolutionsurfacedefinition.html)

Тип данных: VARIANT_BOOL

Синтаксис Automation:

closedShell = iEvolution.closedShell | Получить свойство ([* ](1.html))  
---|---  
iEvolution.closedShell = closedShell | Установить свойство([* ](1.html))  
closedShell = iEvolution.GetClosedShell() | Получить свойство ([**](2.html))  
iEvolution.SetClosedShell(closedShell) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

closedShell = iEvolution.GetClosedShell() | Получить свойство  
---|---  
iEvolution.SetClosedShell(closedShell) | Установить свойство  
  
Значения свойства:

TRUE | \- поверхность замкнута,  
---|---  
FALSE | \- поверхность не замкнута.  
  
Подразделы:

(отсутствуют)
