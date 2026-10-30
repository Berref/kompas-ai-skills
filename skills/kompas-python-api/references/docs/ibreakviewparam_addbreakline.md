# AddBreakLine - Добавить линию разрыва

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Параметры ](bb2370796.html) > [Интерфейс IBreakViewParam ](ibreakviewparam.html) > [IBreakViewParam - методы ](ibreakviewparam_methods.html) |  Scroll [ [ [ ](ibreakviewparam_deletebreakline.html "К следующему разделу")](ibreakviewparam_methods.html "На уровень выше")](ibreakviewparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibreakviewparam.html)

Синтаксис Automation:

long AddBreakLine( double X1,

double Y1,

double X2,

double Y2,

double angle )

Синтаксис COM:

HRESULT AddBreakLine( double X1,

double Y1,

double X2,

double Y2,

double angle

long * Index );

Входные параметры:

X1, Y1, X2, Y2 | \- координаты границы разрыва,  
---|---  
angle | \- угол.  
  
Возвращаемое значение:

| \- индекс линии разрыва.  
---|---  
  
Примечание:

Метод позволяет добавить линию разрыва вида.

Угол первого разрыва может быть произвольным. Последующие разрывы должны быть параллельны или перпендикулярны первому.

Например, в виде создан разрыв, направление сдвига которого расположено под углом 30 градусов к оси Х. Впоследствии в этом виде можно будет создать разрывы, направления сдвига которых располагаются либо под таким же углом, либо под углом 120 градусов к оси Х.

Подразделы:

(отсутствуют)
