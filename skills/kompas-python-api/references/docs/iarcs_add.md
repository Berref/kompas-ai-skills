# Add - Создать дугу (добавить дугу в коллекцию)

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IArcs ](iarcs.html) > [IArcs - методы ](iarcs_methods.html) |  Scroll [ [ [ ](iarcslots.html "К следующему разделу")](iarcs_methods.html "На уровень выше")](iarcs_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iarcs.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add([out, retval] IArc** Result);

Возвращаемое значение:

Result | \- Указатель на базовый интерфейс для дуг [IArc](iarc.html).  
---|---  
  
Примечание:

Метод позволяет создать новый интерфейс дуги. После получения нового интерфейса нужно задать параметры дуги и вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
