# direction - Направление выдавливания

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Элемент выдавливания (Интерфейсы ksExtrusionParam, IExtrusionParam) ](ksextrusionparam.html) > [IExtrusionParam - свойства ](ksextrusionparam_props.html) |  Scroll [ [ [ ](ksextrusionparam_draftoutwardnormal.html "К следующему разделу")](ksextrusionparam_props.html "На уровень выше")](ksextrusionparam_depthreverse.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksextrusionparam.html)

Тип данных: long

Прямое направление совпадает с нормалью, проведенной к плоскости эскиза.

Для вырезаемого элемента выдавливания направление противоположно нормали.

Значения свойства:

| [Типы направлений...](direction_type.html)  
---|---  
  
Синтаксис Automation:

direction = iExtrusionParam.direction | Получить свойство([* ](1.html))  
---|---  
iExtrusionParam.direction = direction | Установить свойство ([* ](1.html))  
direction = iExtrusionParam.GetDirection() | Получить свойство ([**](2.html))  
iExtrusionParam.SetDirection(direction) | Установить свойство ([**](2.html))  
  
Примечание:

Нормаль, проведенная к грани, всегда направлена наружу ("из тела детали").

Подразделы:

(отсутствуют)
