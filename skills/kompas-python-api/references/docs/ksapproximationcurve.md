# ksApproximationCurve - Аппроксимировать кривую дугами

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](kscalcrasterscale.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](getobjparam.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksapproximationcurve_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksApproximationCurve](ksdocument2d_ksapproximationcurve.html).

Синтаксис:

reference ksApproximationCurve (reference p,

double eps,

unsigned char curentLayer,

double maxRad,

unsigned char smooth);

Входные параметры:

p | \- указатель на аппроксимируемую кривую,  
---|---  
eps | \- точность аппроксимации (от 1e-7 до 1)  
curentLayer | \- тип размещения получившихся объектов на слоях: 0 - на слой кривой, 1 - в текущий слой,  
maxRad | \- максимально допустимый радиус дуг, (0 - ограничение не накладывается),  
smooth | \- признак сопряжения: 1 - гладкое, 0 - не гладкое.  
  
Возвращаемое значение:

указатель на контур, дугу, отрезок | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Аппроксимируются кривые Безье, NURBS, эквидистанты, эллипсы, дуги эллипсов и контуры. Остальные кривые игнорируются.

Подразделы:

(отсутствуют)
