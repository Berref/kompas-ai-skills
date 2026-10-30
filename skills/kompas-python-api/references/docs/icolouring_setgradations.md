# SetGradations - Установить параметры переходов цвета

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IColouring ](icolouring.html) > [IColouring - методы ](icolouring_methods.html) |  Scroll [ [ [ ](iconiccurve.html "К следующему разделу")](icolouring_methods.html "На уровень выше")](icolouring_setgradation.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icolouring.html)

Синтаксис Automation:

BOOL SetGradations( VARIANT * Positions,

VARIANT * Colors,

VARIANT * Transparences,

VARIANT * Interpolations );

Синтаксис COM:

HRESULT SetGradations( VARIANT * Positions,

VARIANT * Colors,

VARIANT * Transparences,

VARIANT * Interpolations,

BOOL* Result );

Входные параметры:

Positions | \- массив SAFEARRAY | VT_I4 положений переходов относительно начальной точки заливки в процентах,  
---|---  
Colors | \- массив SAFEARRAY | VT_I4 цветов переходов,  
Transparences | \- массив SAFEARRAY | VT_I4 прозрачностей переходов,  
Interpolations | \- массив SAFEARRAY | VT_BOOL значений опции Интерполирование для переходов.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить параметры переходов цветов.

Подразделы:

(отсутствуют)
