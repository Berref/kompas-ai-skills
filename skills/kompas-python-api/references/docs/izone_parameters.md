# Parameters - Параметры зоны

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Зоны ](cu1735335.html) > [Интерфейс IZone ](izone.html) > [IZone - свойства ](zonetype_propers.html) |  Scroll [ [ [ ](izone_selectobjects.html "К следующему разделу")](zonetype_propers.html "На уровень выше")](izone_zonetype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](izone.html)

Тип данных: Указатель на интерфейс [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

Parameters = Object.Parameters | Получить свойство ([* ](1.html))  
---|---  
Parameters = Object.GetParameters() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Parameters( &Parameters ) | Получить свойство  
---|---  
  
Примечание:

Свойство доступно только для чтения.

В зависимости от способа создания зоны[ IZone::ZoneType](izone_zonetype.html) возвращается интерфейс параметров зоны.

•ksZoneFree - Нет параметров;

•ksZoneByPoints - Параметры зоны заданной габаритным параллелепипедом - [IZoneParametersByBorderPoints](izoneparametersbyborderpoints.html);

•ksZoneByObjects - Параметры зоны по суммарному габариту объектов - [IZoneParametersByObjects](izoneparametersbyobjects.html).

Подразделы:

(отсутствуют)
