# ksDrawSlideEx - Отрисовать слайд (расширенная функция)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](ksdrawslidefromfile.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](ksdrawkompastextw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksDrawSlideEx](kompasobject_ksdrawslideex.html).

Синтаксис:

int ksDrawSlideEx ( void *HWindow,

unsigned int SlideID,

HINSTANCE hInstance );

Входные параметры:

HWindow | \- дескриптор окна,  
---|---  
SlideID | \- номер слайда в файле ресурсов приложения,  
hInstance | \- NULL - отрисовка в текущей библиотеке, hInstance - в подключаемой.  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
