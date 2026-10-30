# PlacementChange - Изменение положения

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksProcess2DNotify\IProcess2DNotify ](ksprocess2dnotify.html) > [События ](ksprocess2dnotify_events.html) |  Scroll [ [ [ ](ksprocess2dnotify_run.html "К следующему разделу")](ksprocess2dnotify_events.html "На уровень выше")](ksprocess2dnotify_executecommand.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksprocess2dnotify.html)

Синтаксис Automation:

BOOL PlacementChange( double X, double Y, double Angle, BOOL Dynamic );

Синтаксис COM:

BOOL PlacementChange( double X, double Y, double Angle, BOOL Dynamic );

Возвращаемое значение:

TRUE | \- если параметры процесса изменились.  
---|---  
  
Входные параметры:

X,Y | \- координаты курсора,  
---|---  
Angle | \- угол,  
Dynamic | TRUE - динамическое изменение положения, FALSE - фиксация положения.  
  
Подразделы:

(отсутствуют)
