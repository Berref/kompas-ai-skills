# Add - Создать элемент и добавить в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IArcSlots](iarcslots.html) > [IArcSlots - методы](iarcslots_methods.html) |  Scroll [ [ [ ](ibeziers.html "К следующему разделу")](iarcslots_methods.html "На уровень выше")](iarcslots_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iarcslots.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add(IArcSlot** Result);

Возвращаемое значение:

| \- указатель на интерфейс дугового паза [IArcSlot](iarcslot.html).  
---|---  
  
Примечание:

Метод позволяет добавить паз в коллекцию. 

После получения нового интерфейса нужно задать параметры паза и вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
