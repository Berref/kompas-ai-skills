# LibHotPnt_UpdateCommand - Установить состояния команд из меню

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Работа с макроэлементами и библиотечными макроэлементами ](cm1919792.html) > [Работа с характерными точками ](cm1878328.html) > [Интерфейс ILibHPObject1 ](ilibhpobject1.html) > [ILibHPObject1 - методы ](ilibhpobject1_methods.html) |  Scroll [ [ [ ](ilibhpobject.html "К следующему разделу")](ilibhpobject1_methods.html "На уровень выше")](ilibhpobject1_libhotpnt_unselect.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibhpobject1.html)

Синтаксис COM:

BOOL LibHotPnt_UpdateCommand( int commandId );

Входной параметр:

commandId | \- идентификатор команды.  
---|---  
  
Возвращаемое значение:

TRUE | \- команда доступна,  
---|---  
FALSE | \- команда недоступна.  
  
Примечание:

Метод позволяет установить состояния команд из меню, присланного по [ILibHPObject::LibHotPnt_GetMenu](ilibhpobject_libhotpnt_getmenu.html) или [ILibHPObject1::LibHotPnt_GetMenuEx](ilibhpobject1_libhotpnt_getmenuex.html).

Подразделы:

(отсутствуют)
