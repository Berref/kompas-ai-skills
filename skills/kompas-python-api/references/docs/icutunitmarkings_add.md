# Add - Создать обозначение узла в сечении и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс ICutUnitMarkings ](icutunitmarkings.html) > [ICutUnitMarkings - методы ](icutunitmarkings_methods.html) |  Scroll [ [ [ ](imultitextleaders.html "К следующему разделу")](icutunitmarkings_methods.html "На уровень выше")](icutunitmarkings_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icutunitmarkings.html)

Синтаксис Automation:

LPDISPATCH Add;

Синтаксис COM:

HRESULT Add( ICutUnitMarking** Result);

Возвращаемое значение:

| \- Указатель на интерфейс обозначения узла в сечении [ICutUnitMarking](icutunitmarking.html).  
---|---  
  
Примечание:

Метод позволяет создать новый интерфейс обозначения узла в сечении. После получения нового интерфейса нужно задать параметры обозначения узла и вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
