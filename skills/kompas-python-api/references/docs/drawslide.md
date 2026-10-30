# DrawSlide - Отрисовать векторный слайд

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](error.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](drawbitmap.html "К предыдущему разделу")  
---|---  
  
[Пример...](drawbitmap_drawslide_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksDrawSlide](kompasobject_ksdrawslide.html).

Синтаксис:

int DrawSlide ( void *Hwindow, unsigned int SlideID );

Входной параметр:

HWindow | \- дескриптор окна, в котором нужно отрисовать слайд,  
---|---  
SlideID | \- идентификатор слайда в файле ресурсов.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
