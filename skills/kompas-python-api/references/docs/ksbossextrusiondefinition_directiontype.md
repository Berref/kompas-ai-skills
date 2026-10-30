# directionType - Направление выдавливания

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Приклеенный элемент выдавливания (Интерфейсы ksBossExtrusionDefinition, IBossExtrusionDefinition) ](ksbossextrusiondefinition.html) > [ksBossExtrusionDefinition - свойства ](ksbossextrusiondefinition_props.html) |  Scroll [ [ [ ](ksbossextrusiondefinition_methods.html "К следующему разделу")](ksbossextrusiondefinition_props.html "На уровень выше")](ksbossextrusiondefinition_choosetype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbossextrusiondefinition.html)

Тип данных: short

Синтаксис Automation:

directionType = iBossExtrusion.directionType | Получить свойство([* ](1.html))  
---|---  
iBossExtrusion.directionType= directionType | Установить свойство ([* ](1.html))  
directionType = iBossExtrusion.GetDirectionType() | Получить свойство ([**](2.html))  
iBossExtrusion.SetDirectionType(directionType) | Установить свойство ([**](2.html))  
  
Значения свойства:

| [Типы направлений...](direction_type.html)  
---|---  
  
Примечание:

1\. Нормаль, проведенная к грани, всегда направлена наружу ("из тела детали").

2\. Прямое направление совпадает с нормалью, проведенной к плоскости эскиза.

3\. Для вырезаемого элемента выдавливания направление противоположно нормали.

Подразделы:

(отсутствуют)
