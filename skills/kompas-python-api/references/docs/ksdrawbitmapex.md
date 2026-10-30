# ksDrawBitmapEx - Отрисовать растровый слайд в заданном окне

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](ksdrawkompasdocument.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](gethwindow.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksDrawBitmapEx](kompasobject_ksdrawbitmapex.html).

Синтаксис:

int ksDrawBitmapEx ( void* HWindow,

unsigned int sldID,

HINSTANCE hInst )

Входной параметр:

HWindow | \- дескриптор окна, в котором нужно отрисовать BITMAP-слайд,  
---|---  
sldID | \- идентификатор BITMAP-слайда в файле ресурсов,  
hInst | \- hInstance текущей библиотеки или NULL, если она одна.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
