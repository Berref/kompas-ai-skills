# directionType - Направление вращения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Поверхность вращения (Интерфейсы ksRotatedSurfaceDefinition и IRotatedSurfaceDefinition) ](ksrotatedsurfacedefinition.html) > [ksRotatedSurfaceDefinition - свойства ](ksrotatedsurfacedefinition_props.html) |  Scroll [ [ [ ](ksrotatedsurfacedefinition_toroidshapetype.html "К следующему разделу")](ksrotatedsurfacedefinition_props.html "На уровень выше")](ksrotatedsurfacedefinition_closedshell.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrotatedsurfacedefinition.html)

Тип данных: short

Значения свойства:

| [Типы направлений...](direction_type.html)  
---|---  
  
Синтаксис Automation:

directionType = iRotatedSurface.directionType | Получить свойство ([* ](1.html))  
---|---  
iRotatedSurface.directionType = directionType | Установить свойство([* ](1.html))  
directionType = iRotatedSurface.GetDirectionType() | Получить свойство ([**](2.html))  
iRotatedSurface.SetDirectionType (directionType) | Установить свойство ([**](2.html))  
  
Примечание:

1\. Прямое направление - вдоль нормали к плоскости эскиза и всегда против часовой стрелки.

2\. Нормаль, проведенная к поверхности тела, всегда выходит из тела.

Подразделы:

(отсутствуют)
