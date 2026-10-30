# directionType - Направление вращения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Приклеееный элемент вращения (Интерфейс ksBossRotatedDefinition, IBossRotatedDefinition) ](ksbossrotateddefinition.html) > [IBossRotatedDefinition - свойства ](ksbossrotateddefinition_props.html) |  Scroll [ [ [ ](ksbossrotateddefinition_toroidshapetype.html "К следующему разделу")](ksbossrotateddefinition_props.html "На уровень выше")](ksbossrotateddefinition_choosetype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbossrotateddefinition.html)

Тип данных: short

Значения свойства:

| [Типы направлений...](direction_type.html)  
---|---  
  
Синтаксис Automation:

directionType = iBossRotated.directionType | Получить свойство([* ](1.html))  
---|---  
iBossRotated.directionType= directionType | Установить свойство ([* ](1.html))  
directionType = iBossRotated.GetDirectionType() | Получить свойство ([**](2.html))  
iBossRotated.SetDirectionType (directionType) | Установить свойство ([**](2.html))  
  
Примечание:

Прямое направление - вдоль нормали к плоскости эскиза и всегда против часовой стрелки.

Нормаль, проведенная к поверхности тела, всегда выходит из тела.

Подразделы:

(отсутствуют)
