# ksTanLinePointCurve - Получить точки касания кривой и прямой, проведенной из заданной точки

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления касаний и сопряжений ](tan_couple_fncts_common.html) |  Scroll [ [ [ ](tancirclecircle.html "К следующему разделу")](tan_couple_fncts_common.html "На уровень выше")](kscouplinglineline.html "К предыдущему разделу")  
---|---  
  
[Пример...](kstanlinepointcurve_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksTanLinePointCurve](ksmathematic2d_kstanlinepointcurve.html).

Синтаксис:

int ksTanLinePointCurve (double x,

double y,

reference pCur,

reference array);

Входные параметры:

pCur | \- указатель на кривую,  
---|---  
x, y | \- координаты точки.  
  
Выходной параметр:

array | \- указатель на динамический массив точек касания MathPointParam[.](structmathpointparam.html)  
---|---  
  
Возвращаемое значение:

количество точек касания | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Динамический массив точек касания array должен быть создан до передачи его в функцию.

Подразделы:

(отсутствуют)
