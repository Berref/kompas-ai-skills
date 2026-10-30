# Current - Указатель на текущую СК

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс ILocalCoordinateSystems ](ilocalcoordinatesystems.html) > [ILocalCoordinateSystems - свойства ](ilocalcoordinatesystems_props.html) |  Scroll [ [ [ ](ilocalcoordinatesystems_localcoordinatesystem.html "К следующему разделу")](ilocalcoordinatesystems_props.html "На уровень выше")](ilocalcoordinatesystems_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystems.html)

Тип данных: указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

LocalCoordinateSystem = iObject.Current() | Получить свойство ([* ](1.html))  
---|---  
LocalCoordinateSystems = iObject.GetCurrent() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Current( &LocalCoordinateSystem ) | Получить свойство  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Если на момент получения свойства текущей является ЛСК, то можно привести интерфейс [IModelObject](imodelobject.html), возвращаемый свойством к [ILocalCoordinateSystem](ilocalcoordinatesystem.html), с помощью [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html). Если же текущей является мировая СК, то привести возвращаемый интерфейс к ILocalCoordinateSystem не удастся.

Подразделы:

(отсутствуют)
