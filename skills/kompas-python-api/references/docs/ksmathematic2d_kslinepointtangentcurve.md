# ksLinePointTangentCurve - Получить прямую через точку перпендикулярно данной кривой

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_ksmovepointoncurveex.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksgetcurvepointprojectionex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksLinePointTangentCurve](kslinepointtangentcurve.html).

Синтаксис Automation:

BOOL ksLinePointTangentCurve( long p, double x, double y, LPDISPATCH param );

Входные параметры:

p | \- указатель на кривую,  
---|---  
x, y | \- координаты точки.  
  
Выходной параметр:

param | \- указатель на интерфейс динамического массива ksDynamicArray углов касательных типа DOUBLE_ARR.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
