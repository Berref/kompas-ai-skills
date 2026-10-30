# ksDrawSlideFromFileW - Отрисовать слайд в окне из текстового файла, содержащего блок RCDATA (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](ksinitfilepreviewfunc.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](ksdrawslidefromfile.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksDrawSlideFromFile](kompasobject_ksdrawslidefromfile.html).

Синтаксис:

int LIB_FUNC ksDrawSlideFromFileW ( void *Hwindow, LPWSTR fileName );

Входной параметр:

Hwindow | \- дескриптор окна,  
---|---  
fileName | \- полное имя файла.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Функция предназначена для отладки слайдов. Позволяет просмотреть отредактированный слайд в окне диалога без перетрансляции тестовой библиотеки.

2\. При использовании ANSI следует использовать функцию [ksDrawSlideFromFile](ksdrawslidefromfile.html).

Подразделы:

(отсутствуют)
