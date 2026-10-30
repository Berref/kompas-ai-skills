# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IInclines ](iinclines.html) > [IInclines - методы ](iinclines_methods.html) |  Scroll [ [ [ ](iisoparametriccurves.html "К следующему разделу")](iinclines_methods.html "На уровень выше")](iinclines_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinclines.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IIncline ** Result );

Возвращаемое значение:

| \- указатель на интерфейс [IIncline](iincline.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс операции Уклон.

2\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
