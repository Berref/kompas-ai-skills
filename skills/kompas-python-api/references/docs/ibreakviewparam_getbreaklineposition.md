# GetBreakLinePosition - Получить координаты границ разрыва

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Параметры ](bb2370796.html) > [Интерфейс IBreakViewParam ](ibreakviewparam.html) > [IBreakViewParam - методы ](ibreakviewparam_methods.html) |  Scroll [ [ [ ](ibreakviewparam_setbreaklineparams.html "К следующему разделу")](ibreakviewparam_methods.html "На уровень выше")](ibreakviewparam_getbreaklineparams.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibreakviewparam.html)

Синтаксис Automation:

BOOL GetBreakLinePosition( long Index,

double * X1,

double * Y1,

double * X2,

double * Y2 )

Синтаксис COM:

HRESULT GetBreakLinePosition( long Index,

double * X1,

double * Y1,

double * X2,

double * Y2,

BOOL * Result );

Входные параметры:

Index | \- индекс линии разрыва.  
---|---  
  
Выходные параметры:

X1, Y1, X2, Y2 | \- координаты границы разрыва.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получать координаты границ разрыва.

Подразделы:

(отсутствуют)
