# Detach - Отсоединить слой

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Слои ](cu1735361.html) > [Интерфейс ILayers3D ](ilayers3d.html) > [ILayers3D - методы ](ilayers3d_methods.html) |  Scroll [ [ [ ](ilayergroups3d.html "К следующему разделу")](ilayers3d_methods.html "На уровень выше")](ilayers3d_attach.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayers3d.html)

Синтаксис Automation:

BOOL Detach( ILayer3D * PVal );

Синтаксис COM:

HRESULT Detach( ILayer3D * PVal, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

PVal | \- указатель на интерфейс слоя [ILayer3D](ilayer3d.html).  
---|---  
  
Возвращаемое значение:

| \- Полный путь к библиотеке на диске.  
---|---  
  
Примечание:

1\. Интерфейс слоя отсоединяется от коллекции, слой при этом из документа не удаляется.

2\. Метод работает только для коллекции слоев группы [ILayerGroup3D](ilayergroup3d.html), если она не является динамической.

Подразделы:

(отсутствуют)
