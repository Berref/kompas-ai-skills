# FilePreviewFuncCallBack - Прототип функции обратной связи для функций выбора файлов

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](filepreviewfunccallbackw.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](errorw.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksinitfilepreviewfunc_example.html)

Синтаксис:

typedef int ( WINAPI *FilePreviewFuncCallBack )( HWND HWindow, char * fileName );

Входные параметры:

HWindow | \- дескриптор окна просмотра,  
---|---  
fileName | \- файл, который нужно показать в окне просмотра.  
  
Возвращаемое значение:

1 | \- если файл отрисован,  
---|---  
0 | \- если файл не отрисован.  
  
См. также:

[ksInitFilePreviewFunc](ksinitfilepreviewfunc.html)

Примечание.

При использовании Unicode следует использовать функцию [FilePreviewFuncCallBackW](filepreviewfunccallbackw.html).

Подразделы:

(отсутствуют)
