# Add - Создать обозначение узла и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IUnitMarkings ](iunitmarkings.html) > [IUnitMarkings - методы ](iunitmarkings_methods.html) |  Scroll [ [ [ ](iunitnumbers.html "К следующему разделу")](iunitmarkings_methods.html "На уровень выше")](iunitmarkings_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iunitmarkings.html)

Синтаксис Automation:

LPDISPATCH Add;

Синтаксис COM:

HRESULT Add( IUnitMarking** Result);

Возвращаемое значение:

| \- Указатель на интерфейс обозначения узла [IUnitMarking](iunitmarking.html).  
---|---  
  
Примечание:

Метод позволяет создать новый интерфейс обозначения узла. После получения нового интерфейса нужно задать параметры обозначения узла и вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
