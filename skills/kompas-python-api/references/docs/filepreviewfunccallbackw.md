# FilePreviewFuncCallBackW - Прототип функции обратной связи для функций выбора файлов (Unicode )

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](getparenthwindow.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](filepreviewfunccallback.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

typedef int ( WINAPI *FilePreviewFuncCallBackW )( HWND HWindow, LPWSTR fileName );

Входные параметры:

HWindow | \- дескриптор окна просмотра,  
---|---  
fileName | \- файл, который нужно показать в окне просмотра.  
  
Возвращаемое значение:

1 | \- если файл отрисован,  
---|---  
0 | \- если файл не отрисован.  
  
См. также:

[ksInitFilePreviewFuncW](ksinitfilepreviewfuncw.html)

Примечание.

При использовании ANSI следует использовать функцию [FilePreviewFuncCallBack](filepreviewfunccallback.html).

Подразделы:

(отсутствуют)
