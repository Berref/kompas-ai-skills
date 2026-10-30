# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Измерения ](cu1736454.html) > [Интерфейс IEdgeLengthMeasurements3D ](iedgelengthmeasurements3d.html) > [IEdgeLengthMeasurements3D - методы ](iedgelengthmeasurements3d_methods.html) |  Scroll [ [ [ ](iedgelengthmeasurement3d.html "К следующему разделу")](iedgelengthmeasurements3d_methods.html "На уровень выше")](iedgelengthmeasurements3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iedgelengthmeasurements3d.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IEdgeLengthMeasurement3D * * Result );

Возвращаемое значение:

| \- указатель на интерфейс [IEdgeLengthMeasurement3D](iedgelengthmeasurement3d.html).  
---|---  
  
Примечание:

1\. Метод позволяет создать новый интерфейс объекта измерение длины ребра.

2\. После получения нового интерфейса нужно задать параметры измерения и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
