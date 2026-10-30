# ksInitFilePreviewFuncW - Инициализировать адрес пользовательской функции просмотра пользовательского файла (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](kssetdebugmessagesmode.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](ksinitfilepreviewfunc.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksInitFilePreviewFuncW](ksdocument2d_ksinitfilepreviewfuncw.html).

Синтаксис:

int ksInitFilePreviewFuncW ( FilePreviewFuncCallBackW func );

Входные параметры:

func | \- пользовательская функция просмотра пользовательского файла.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
См. также:

[FilePreviewFuncCallBackW](filepreviewfunccallbackw.html)

Примечание:

1\. Если func вернет 1 - функция отрисовала файл, если 0 - функция не отрисовала файл, файл будет отрисовывать КОМПАС.

2\. При использовании ANSI следует использовать функцию [ksInitFilePreviewFunc](ksinitfilepreviewfunc.html).

Подразделы:

(отсутствуют)
