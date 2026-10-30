# Add - Создать элемент и добавить в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IStraightSlots ](istraightslots.html) > [IStraightSlots - методы](istraightslots_metods.html) |  Scroll [ [ [ ](iarc.html "К следующему разделу")](istraightslots_metods.html "На уровень выше")](istraightslots_metods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](istraightslots.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add (IStraightSlot ** Result);

Возвращаемое значение:

| \- Указатель на интерфейс паза [IStraightSlot](istraightslot.html).  
---|---  
  
Примечание:

Метод позволяет добавить паз в коллекцию. 

После получения нового интерфейса нужно задать параметры паза и вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
