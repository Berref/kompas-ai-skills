# LocalCoordinateSystem - Указатель на элемент, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс ILocalCoordinateSystems ](ilocalcoordinatesystems.html) > [ILocalCoordinateSystems - свойства ](ilocalcoordinatesystems_props.html) |  Scroll [ [ [ ](ilocalcoordinatesystems_methods.html "К следующему разделу")](ilocalcoordinatesystems_props.html "На уровень выше")](ilocalcoordinatesystems_current.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystems.html)

Тип данных: указатель на интерфейс [ILocalCoordinateSystem](ilocalcoordinatesystem.html)

Синтаксис Automation:

LocalCoordinateSystem = iObject.LocalCoordinateSystem( index ) | Получить свойство ([* ](1.html))  
---|---  
LocalCoordinateSystem = iObject.GetLocalCoordinateSystem( index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LocalCoordinateSystem( index, &LocalCoordinateSystem ) | Получить свойство  
---|---  
  
Входные параметры:

Index | \- VT_I4 - индекс объекта.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
