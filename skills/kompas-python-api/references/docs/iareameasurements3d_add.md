# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Измерения ](cu1736454.html) > [Интерфейс IAreaMeasurements3D ](iareameasurements3d.html) > [IAreaMeasurements3D - методы ](iareameasurements3d_methods.html) |  Scroll [ [ [ ](iareameasurement3d.html "К следующему разделу")](iareameasurements3d_methods.html "На уровень выше")](iareameasurements3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iareameasurements3d.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IAreaMeasurement3D * * Result );

Возвращаемое значение:

| \- указатель на интерфейс [IAreaMeasurement3D](iareameasurement3d.html)  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс измерения площади.

2\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
