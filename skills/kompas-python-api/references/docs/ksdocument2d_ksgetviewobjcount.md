# ksGetViewObjCount - Получить количество объектов в виде

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Навигация ](bt1742269.html) |  Scroll [ [ [ ](ksdocument2d_kskeepreference.html "К следующему разделу")](bt1742269.html "На уровень выше")](ksdocument2d_ksgetobjgabaritrect.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [GetViewObjCount](getviewobjcount.html).

Синтаксис Automation:

long ksGetViewObjCount (long p);

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
