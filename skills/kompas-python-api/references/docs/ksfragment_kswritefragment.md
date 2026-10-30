# ksWriteFragment - Записать группу во фрагмент

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Фрагмент (Интерфейс ksFragment) ](ksfragment.html) > [ksFragment - методы ](ksfragment_methods.html) |  Scroll [ [ [ ](ksstamp.html "К следующему разделу")](ksfragment_methods.html "На уровень выше")](ksfragment_ksreadfragmenttogroupex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfragment.html)

Аналог данного метода при использовании API экспортных функций - [WriteFragment](writefragment.html).

Синтаксис Automation:

long ksWriteFragment (long gr,

LPCTSTR fileName,

LPCTSTR comment,

double xb,

double yb);

Входные параметры:

gr | \- указатель на группу (0 - записывается группа селектирования),  
---|---  
filename | \- имя файла фрагмента,  
comment | \- комментарий для фрагмента,  
xb, yb | \- координаты точки привязки.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
