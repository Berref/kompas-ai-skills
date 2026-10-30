# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IFillets ](ifillets.html) > [IFillets - методы ](ifillets_methods.html) |  Scroll [ [ [ ](ifilletcurves.html "К следующему разделу")](ifillets_methods.html "На уровень выше")](ifillets_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifillets.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IFillet ** Result );

Возвращаемое значение:

| \- указатель на интерфейс [IFillet](ifillet.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс операции скругления.

2\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
