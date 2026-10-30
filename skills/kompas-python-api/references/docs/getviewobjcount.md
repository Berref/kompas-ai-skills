# GetViewObjCount - Получить количество объектов вида

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Навигация по графическому документу ](cm1745694.html) > [Функции навигации ](navigation_fncts.html) |  Scroll [ [ [ ](moveiterator.html "К следующему разделу")](navigation_fncts.html "На уровень выше")](getobjgabaritrect.html "К предыдущему разделу")  
---|---  
  
[Пример...](getviewobjcount_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetViewObjCount](ksdocument2d_ksgetviewobjcount.html).

Синтаксис:

long GetViewObjCount (reference p);

Входной параметр:

p | \- указатель на вид.  
---|---  
  
Возвращаемое значение:

количество объектов в виде | \- в случае удачного завершения,  
---|---  
-1 | \- в случае неудачи.  
  
Примечание:

В случае, если p=0, возвращается число объектов текущего вида или фрагмента.

Подразделы:

(отсутствуют)
