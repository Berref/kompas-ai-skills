# ksClearRegion - Очистить указанную область внутри или снаружи границ, заданных группой объектов

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Операции редактирования ](bt1734633.html) |  Scroll [ [ [ ](ksdocument2d_kscopyobj.html "К следующему разделу")](bt1734633.html "На уровень выше")](ksdocument2d_ksapproximationcurve.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksClearRegion](ksclearregion.html).

Синтаксис Automation:

long ksClearRegion (long grClear,

long grRegion,

BOOL inside);

Входные параметры:

grClear | \- группа геометрии, которую нужно очистить (0 - просматривать все объекты текущего вида),  
---|---  
grRegion | \- группа объектов, задающая область очистки,  
inside | \- признак расположения удаляемых объектов: 0 - снаружи области, ограниченной grRegion, 1 - внутри области.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
