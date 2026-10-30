# directionType - Направление выдавливания

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Вырезанный элемент выдавливания (Интерфейсы ksCutExtrusionDefinition, ICutExtrusionDefinition) ](kscutextrusiondefinition.html) > [ICutExtrusionDefinition - свойства ](kscutextrusiondefinition_props.html) |  Scroll [ [ [ ](kscutextrusiondefinition_methods.html "К следующему разделу")](kscutextrusiondefinition_props.html "На уровень выше")](kscutextrusiondefinition_cut.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutextrusiondefinition.html)

Тип данных: short

Синтаксис Automation:

directionType = iCutExtrusion.directionType | Получить свойство([* ](1.html))  
---|---  
iCutExtrusion.directionType= directionType | Установить свойство ([* ](1.html))  
directionType = iCutExtrusion.GetDirectionType() | Получить свойство ([**](2.html))  
iCutExtrusion.SetDirectionType(directionType) | Установить свойство ([**](2.html))  
  
Значения свойства:

| [Типы направлений..](direction_type.html)  
---|---  
  
Примечание:

1\. Нормаль, проведенная к грани, всегда направлена наружу ("из тела детали").

2\. Прямое направление совпадает с нормалью, проведенной к плоскости эскиза.

3\. Для вырезаемого элемента выдавливания направление противоположно нормали.

Подразделы:

(отсутствуют)
