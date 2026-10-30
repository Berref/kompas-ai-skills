# direction - Направление вращения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры элемента вращения (Интерфейсы ksRotatedParam, IRotatedParam) ](ksrotatedparam.html) > [IRotatedParam - свойства ](ksrotatedparam_props.html) |  Scroll [ [ [ ](ksrotatedparam_toroidshape.html "К следующему разделу")](ksrotatedparam_props.html "На уровень выше")](ksrotatedparam_anglereverse.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksrotatedparam.html)

Тип данных: long

Значения свойства:

| [Типы направлений...](direction_type.html)  
---|---  
  
Синтаксис Automation:

direction = iRotatedParam.direction | Получить свойство([* ](1.html))  
---|---  
iRotatedParam.direction = direction | Установить свойство ([* ](1.html))  
direction = iRotatedParam.GetDirection() | Получить свойство ([**](2.html))  
iRotatedParam.SetDirection(direction) | Установить свойство ([**](2.html))  
  
Примечание:

Прямое направление - вдоль нормали к плоскости эскиза и всегда против часовой стрелки.

Нормаль, проведенная к поверхности тела, всегда выходит из тела.

Подразделы:

(отсутствуют)
