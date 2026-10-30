# Parameters - Параметры зоны

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Зоны ](cu1735335.html) > [Интерфей IZoneDivision ](izonedivision.html) > [IZoneDivision - свойства ](izonedivision_propers.html) |  Scroll [ [ [ ](izonedivision_zone.html "К следующему разделу")](izonedivision_propers.html "На уровень выше")](izonedivision_propers.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](izonedivision.html)

Тип данных: Указатель на интерфейс IKompasAPIObject

Синтаксис Automation:

Parameters = Object.Parameters | Получить свойство ([* ](1.html))  
---|---  
Parameters = Object.GetParameters() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Parameters( &Parameters ) | Получить свойство  
---|---  
  
Примечание:

Свойство доступно только для чтения.

В зависимости от способа создания зоны [IZoneDivision::ZoneDivisionType](izonedivision_zonedivisiontype.html) возвращается интерфейс параметров зоны.

•ksZoneDivisionRegular - Параметры разбиения зоны для способа Равномерно по осям - [IZoneDivisionParametersRegular](izonedivisionparametersregular.html);

•ksZoneDivisionByPlanes - Параметры разбиения зоны для способа По набору плоскостей - [IZoneDivisionParametersByPlanes](izonedivisionparametersbyplanes.html).

Подразделы:

(отсутствуют)
