# SetCurrent - Установить ЛСК в качестве текущей СК

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс ILocalCoordinateSystems ](ilocalcoordinatesystems.html) > [ILocalCoordinateSystems - методы ](ilocalcoordinatesystems_methods.html) |  Scroll [ [ [ ](ilocalcsaxesdirectionparam.html "К следующему разделу")](ilocalcoordinatesystems_methods.html "На уровень выше")](ilocalcoordinatesystems_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystems.html)

Синтаксис Automation:

BOOL SetCurrent( ILocalCoordinateSystem * object );

Синтаксис COM:

HRESULT SetCurrent( ILocalCoordinateSystem * object,

BOOL * Result );

Входные параметры:

| \- Указатель на интерфейс ЛСК [ILocalCoordinateSystem](ilocalcoordinatesystem.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Метод позволяет установить ЛСК, передаваемую входным параметром, в качестве текущей СК.

2\. Если входным параметром передать NULL, текущей станет мировая СК. См. также [ILocalCoordinateSystem::Current](ilocalcoordinatesystem_current.html).

Подразделы:

(отсутствуют)
