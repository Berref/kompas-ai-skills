# GetGradations - Получить параметры переходов цвета

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IColouring ](icolouring.html) > [IColouring - методы ](icolouring_methods.html) |  Scroll [ [ [ ](icolouring_setgradation.html "К следующему разделу")](icolouring_methods.html "На уровень выше")](icolouring_getgradation.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icolouring.html)

Синтаксис Automation:

BOOL GetGradations( VARIANT * Positions,

VARIANT * Colors,

VARIANT * Transparences,

VARIANT * Interpolations );

Синтаксис COM:

HRESULT GetGradations( VARIANT * Positions,

VARIANT * Colors,

VARIANT * Transparences,

VARIANT * Interpolations,

BOOL * Result );

Выходные параметры:

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

Метод позволяет получить параметры переходов цветов.

Подразделы:

(отсутствуют)
