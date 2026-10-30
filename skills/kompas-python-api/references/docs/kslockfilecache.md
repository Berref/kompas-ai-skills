# ksLockFileCache - Выключить/включить кеширование поиска файлов

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](kssavefile.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksgetrelativepathfromsystempathw.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

int LIB_FUNC ksLockFileCache( int lock );

Входные параметры:

lock | \- TRUE - запретить кеширование, \- FALSE - разрешить кеширование.  
---|---  
  
Возвращаемое значение:

Предыдущее значение флага.

Примечание:

Кеширование включается при запуске библиотечной команды.

Подразделы:

(отсутствуют)
