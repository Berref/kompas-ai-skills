# ksCalcInertiaProperties - Получить плоские массово-центровочные характеристики кривой или группы кривых

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления длин, расстояний, углов и МЦХ ](measures_fncts_common.html) |  Scroll [ [ [ ](kscalcmassinertiaproperties.html "К следующему разделу")](measures_fncts_common.html "На уровень выше")](distancepntpnt.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetcurveperimeter_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksCalcInertiaProperties](ksmathematic2d_kscalcinertiaproperties.html).

Синтаксис:

int ksCalcInertiaProperties (reference p,

InertiaParam * properties,

unsigned char dimension);

Входные параметры:

p | \- указатель на кривую или группу кривых,  
---|---  
dimension | \- размерность длины.  
  
[Размерности длины...](lentypes.html)

Выходные параметры:

properties | \- указатель на [структуру параметров для расчета плоских МЦХ](structinertiaparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Кривые должны быть замкнутыми и представлять собой наружные и внутренние контура.

Подразделы:

(отсутствуют)
