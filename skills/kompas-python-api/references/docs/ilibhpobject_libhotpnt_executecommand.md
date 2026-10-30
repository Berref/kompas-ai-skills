# LibHotPnt_ExecuteCommand - Выполнить команду из меню, присланного по LibHotPnt_GetMenu()

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Работа с макроэлементами и библиотечными макроэлементами ](cm1919792.html) > [Работа с характерными точками ](cm1878328.html) > [Интерфейс ILibHPObject ](ilibhpobject.html) > [ILibHPObject- методы ](ilibhpobject_methods.html) |  Scroll [ [ [ ](ilibhpobject_libhotpnt_get.html "К следующему разделу")](ilibhpobject_methods.html "На уровень выше")](ilibhpobject_libhotpnt_complete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibhpobject.html)

Синтаксис:

BOOL LibHotPnt_ExecuteCommand(int id);

Входной параметр:

id | \- идентификатор команды контекстного меню.  
---|---  
  
Возвращаемое значение:

TRUE | \- что-то изменилось и требуется передача в UNDO и пересчет положения характерных точек,  
---|---  
FALSE | \- команда не обработана.  
  
Описание:

Этот метод позволяет отработать событие выбора команды контекстного меню, полученного методами [ILibHPObject::LibHotPnt_GetMenu](ilibhpobject_libhotpnt_getmenu.html) и [ILibHPObject1::LibHotPnt_GetMenuEx,](ilibhpobject1_libhotpnt_getmenuex.html) и выполнить команду с присланным идентификатором.

Выбор команды контекстного меню осуществляется нажатием левой кнопки мыши в габарите команды меню.

Библиотека может изменить отображение библиотечного элемента или выполнить другие действия, связанные с этим событием.

См также метод [LibHotPnt_GetMenu()](ilibhpobject_libhotpnt_getmenu.html)

Подразделы:

(отсутствуют)
