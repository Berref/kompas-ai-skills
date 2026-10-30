# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Измерения ](cu1736454.html) > [Интерфейс IDistanceAngleMeasurements3D ](idistanceanglemeasurements3d.html) > [IDistanceAngleMeasurements3D - методы ](idistanceanglemeasurements3d_methods.html) |  Scroll [ [ [ ](idistanceanglemeasurement3d.html "К следующему разделу")](idistanceanglemeasurements3d_methods.html "На уровень выше")](idistanceanglemeasurements3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idistanceanglemeasurements3d.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IDistanceAngleMeasurement3D * * Result );

Возвращаемое значение:

| \- указатель на интерфейс [IDistanceAngleMeasurement3D](idistanceanglemeasurement3d.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс измерения расстояния и угла.

2\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
