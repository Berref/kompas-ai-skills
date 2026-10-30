# directionType - Направление выдавливания

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Поверхность выдавливания (Интерфейсы ksExtrusionSurfaceDefinition и IExtrusionSurfaceDefinition) ](ksextrusionsurfacedefinition.html) > [ksExtrusionSurfaceDefinition - свойства ](ksextrusionsurfacedefinition_props.html) |  Scroll [ [ [ ](ksextrusionsurfacedefinition_methods.html "К следующему разделу")](ksextrusionsurfacedefinition_props.html "На уровень выше")](ksextrusionsurfacedefinition_closedshell.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksextrusionsurfacedefinition.html)

Тип данных: short

Синтаксис Automation:

directionType = iExtrusionSurface.directionType | Получить свойство ([* ](1.html))  
---|---  
iExtrusionSurface.directionType= directionType | Установить свойство([* ](1.html))  
directionType = iExtrusionSurface.GetDirectionType() | Получить свойство ([**](2.html))  
iExtrusionSurface.SetDirectionType(directionType) | Установить свойство ([**](2.html))  
  
Значения свойства:

| [Типы направлений...](direction_type.html)  
---|---  
  
Примечание:

1\. Нормаль, проведенная к грани, всегда направлена наружу ("из тела детали").

2\. Прямое направление совпадает с нормалью, проведенной к плоскости эскиза.

3\. Для вырезаемого элемента выдавливания направление противоположно нормали.

Подразделы:

(отсутствуют)
