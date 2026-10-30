# ksGetCursorPosition - Получить координаты курсора

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_ksgetcursorlimit.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_ksfindobj.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksGetCursorPosition](ksgetcursorposition.html).

Синтаксис Automation:

long ksGetCursorPosition (double* x, double* y, long type);

Входной параметр:

type | \- признак, какие координаты возвращать: 0 - без учета привязок, 1 - с учетом привязок.  
---|---  
  
Выходные параметры:

x, y | \- координаты курсора (в миллиметрах).  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
