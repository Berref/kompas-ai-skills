# ksGetCurvePerpendicularByT - Получить угол нормали к кривой в заданной точке по параметру кривой

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](ksgeteditmacrovisibleregime.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](kseditviewobject.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

double LIB_FUNC ksGetCurvePerpendicularByT( reference curve,

double t )

Входные параметры:

curve | \- указатель на кривую,  
---|---  
t | \- параметр кривой.  
  
Возвращаемое значение:

Функция возвращает угол нормали к кривой в заданной точке по параметру кривой (0 - 360 градусов). В случае неудачи возвращается -1.

Подразделы:

(отсутствуют)
