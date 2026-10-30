# directionType - Направление вращения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Основание — элемент вращения (Интерфейсы ksBaseRotatedDefinition, IBaseRotatedDefinition) ](ksbaserotateddefinition.html) > [IBaseRotatedDefinition - свойства ](ksbaserotateddefinition_props.html) |  Scroll [ [ [ ](ksbaserotateddefinition_toroidshapetype.html "К следующему разделу")](ksbaserotateddefinition_props.html "На уровень выше")](ksbaserotateddefinition_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbaserotateddefinition.html)

Тип данных: short

Синтаксис Automation:

directionType = iBaseRotated.directionType | Получить свойство([* ](1.html))  
---|---  
iBaseRotated.directionType= directionType | Установить свойство ([* ](1.html))  
directionType = iBaseRotated.GetDirectionType() | Получить свойство ([**](2.html))  
iBaseRotated.SetDirectionType (directionType) | Установить свойство ([**](2.html))  
  
Значения свойства:

| [Типы направлений...](direction_type.html)  
---|---  
  
Примечание:

1\. Прямое направление - вдоль нормали к плоскости эскиза и всегда против часовой стрелки.

2\. Нормаль, проведенная к поверхности тела, всегда выходит из тела.

Подразделы:

(отсутствуют)
