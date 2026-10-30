# directionType - Направление вращения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Вырезанный элемент вращения(ИнтерфейсыksCutRotatedDefinition, ICutRotatedDefinition) ](kscutrotateddefinition.html) > [ICutRotatedDefinition - свойства ](kscutrotateddefinition_props.html) |  Scroll [ [ [ ](kscutrotateddefinition_toroidshapetype.html "К следующему разделу")](kscutrotateddefinition_props.html "На уровень выше")](kscutrotateddefinition_cut.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutrotateddefinition.html)

Тип данных: short

Значения свойства:

| [Типы направлений...](direction_type.html)  
---|---  
  
Синтаксис Automation:

directionType = iCutRotated.directionType | Получить свойство([* ](1.html))  
---|---  
iCutRotated.directionType= directionType | Установить свойство ([* ](1.html))  
directionType = iCutRotated.GetDirectionType() | Получить свойство ([**](2.html))  
iCutRotated.SetDirectionType (directionType) | Установить свойство ([**](2.html))  
  
Примечание:

1\. Прямое направление - вдоль нормали к плоскости эскиза и всегда против часовой стрелки.

2\. Нормаль, проведенная к поверхности тела, всегда выходит из тела.

Подразделы:

(отсутствуют)
