# DrawBitmap - Отрисовать растровый слайд

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](drawslide.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](cursorcallbackw.html "К предыдущему разделу")  
---|---  
  
[Пример...](drawbitmap_drawslide_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksDrawBitmap](kompasobject_ksdrawbitmap.html).

Синтаксис:

int DrawBitmap ( void *Hwindow, unsigned int BitmapID );

Входной параметр:

HWindow | \- дескриптор окна, в котором нужно отрисовать BITMAP-слайд,  
---|---  
BitmapID | \- идентификатор BITMAP в файле ресурсов.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
