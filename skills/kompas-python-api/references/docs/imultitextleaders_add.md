# Add - Создать выносную надпись к многослойным конструкциям (Добавить объект в коллекцию)

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMultiTextLeaders ](imultitextleaders.html) > [IMultiTextLeaders - методы ](imultitextleaders_methods.html) |  Scroll [ [ [ ](iunitmarkings.html "К следующему разделу")](imultitextleaders_methods.html "На уровень выше")](imultitextleaders_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultitextleaders.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add([out, retval] IMultiTextLeader** Result);

Возвращаемое значение:

| \- указатель на интерфейс [IMultiTextLeader](imultitextleader.html)  
---|---  
  
Примечание:

После получения нового интерфейса нужно задать параметры объекта и вызвать метод [IDrawingObject::Update](idrawingobject_update.html). Объект в модели появится после вызова этого метода.

Подразделы:

(отсутствуют)
