# ksInitFilePreviewFunc - Инициализировать адрес пользовательской функции просмотра пользовательского файла

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](ksinitfilepreviewfuncw.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](ksdrawslidefromfilew.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksinitfilepreviewfunc_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksInitFilePreviewFunc](ksdocument2d_ksinitfilepreviewfunc.html).

Синтаксис:

int ksInitFilePreviewFunc ( FilePreviewFuncCallBack func );

Входные параметры:

func | \- пользовательская функция просмотра пользовательского файла.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
См. также:

[FilePreviewFuncCallBack](filepreviewfunccallback.html)

Примечание:

1\. Если func вернет 1 - функция отрисовала файл, если 0 - функция не отрисовала файл, файл будет отрисовывать КОМПАС.

2\. При использовании Unicode следует использовать функцию [ksInitFilePreviewFuncW](ksinitfilepreviewfuncw.html).

Подразделы:

(отсутствуют)
