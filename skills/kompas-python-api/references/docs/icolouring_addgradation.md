# AddGradation - Добавить переход цвета

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IColouring ](icolouring.html) > [IColouring - методы ](icolouring_methods.html) |  Scroll [ [ [ ](icolouring_cleargradations.html "К следующему разделу")](icolouring_methods.html "На уровень выше")](icolouring_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icolouring.html)

Синтаксис Automation:

long AddGradation( long Position,

long Color,

long Transparency,

BOOL Interpolation );

Синтаксис COM:

HRESULT AddGradation( long Position,

long Color,

long Transparency,

BOOL Interpolation,

long * Result );

Входные параметры:

Position | \- положение перехода относительно начальной точки заливки в процентах,  
---|---  
Color | \- цвет перехода,  
Transparency | \- прозрачность перехода,  
Interpolation | \- значений опции Интерполирование для перехода.  
  
Возвращаемое значение:

| \- индекс перехода.  
---|---  
  
Примечание:

Метод позволяет установить параметры переход цвета.

Подразделы:

(отсутствуют)
