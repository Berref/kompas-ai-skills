# ksSetLibraryEnable - Запретить/разрешить продукт (занять лицензию)

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](kssetlookstyle.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](kssetcriticalprocess.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

int LIB_FUNC ksSetLibraryEnable( unsigned int prodNumb,

unsigned char enable );

Входные параметры:

prodNumb | \- Номер продукта.  
---|---  
enable | \- TRUE - Занять лицензию FALSE - Отпустить лицензию  
  
Возвращаемое значение

TRUE | \- если попытка получить лицензию выполнялась.  
---|---  
  
Подразделы:

(отсутствуют)
