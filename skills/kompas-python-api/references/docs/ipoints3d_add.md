# Add - Создать новый элемент и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoints3D ](ipoints3d.html) > [IPoints3D - методы ](ipoints3d_methods.html) |  Scroll [ [ [ ](ipoint3d.html "К следующему разделу")](ipoints3d_methods.html "На уровень выше")](ipoints3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoints3d.html)

Синтаксис Automation:

LPDISPATCH Add;

Синтаксис COM:

HRESULT Add( IPoint3D** Result);

Возвращаемое значение:

| Указатель на интерфейс пространственной точки [IPoint3D](ipoint3d.html).  
---|---  
  
Примечание:

Метод позволяет создать новый интерфейс пространственной точки. После получения нового интерфейса нужно задать параметры элемента и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
