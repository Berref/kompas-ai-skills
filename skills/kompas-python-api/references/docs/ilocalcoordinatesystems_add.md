# Add - Создать новый элемент и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс ILocalCoordinateSystems ](ilocalcoordinatesystems.html) > [ILocalCoordinateSystems - методы ](ilocalcoordinatesystems_methods.html) |  Scroll [ [ [ ](ilocalcoordinatesystems_setcurrent.html "К следующему разделу")](ilocalcoordinatesystems_methods.html "На уровень выше")](ilocalcoordinatesystems_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystems.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( ILocalCoordinateSystem** Result);

Возвращаемое значение:

| \- Указатель на интерфейс ЛСК [ILocalCoordinateSystem](ilocalcoordinatesystem.html).  
---|---  
  
Примечание:

1\. Метод позволяет создать новый интерфейс локальной системы координат.

2\. После получения нового интерфейса нужно задать параметры и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
