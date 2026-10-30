# SetGradation - Установить параметры перехода цвета по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IColouring ](icolouring.html) > [IColouring - методы ](icolouring_methods.html) |  Scroll [ [ [ ](icolouring_setgradations.html "К следующему разделу")](icolouring_methods.html "На уровень выше")](icolouring_getgradations.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icolouring.html)

Синтаксис Automation:

BOOL SetGradation( long Index,

long * Position,

long * Color,

long * Transparency,

BOOL * Interpolation );

Синтаксис COM:

HRESULT SetGradation( long Index,

long * Position,

long * Color,

long * Transparency,

BOOL * Interpolation,

BOOL * Result );

Входные параметры:

Index | \- индекс перехода,  
---|---  
Position | \- положение перехода относительно начальной точки заливки в процентах,  
Color | \- цвет перехода,  
Transparency | \- прозрачность перехода,  
Interpolation | \- значений опции Интерполирование для перехода.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить параметры перехода цвета по индексу.

Подразделы:

(отсутствуют)
