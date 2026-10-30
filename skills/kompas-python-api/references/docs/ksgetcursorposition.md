# ksGetCursorPosition - Получить координаты курсора

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции ввода параметров ](enter_params_common.html) |  Scroll [ [ [ ](ksgetcursorlimit.html "К следующему разделу")](enter_params_common.html "На уровень выше")](ksexecdialspecialsymbol.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetcursorposition_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetCursorPosition](ksdocument2d_ksgetcursorposition.html)

Синтаксис:

int ksGetCursorPosition (double *x,

double *y,

int type);

Входные параметры:

x,y | \- координаты курсора в миллиметрах,  
---|---  
type | \- признак способа определения координат: 0 - без учета привязок, 1 - с учетом привязок.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи или если курсор находится не на поле чертежа.  
  
Подразделы:

(отсутствуют)
