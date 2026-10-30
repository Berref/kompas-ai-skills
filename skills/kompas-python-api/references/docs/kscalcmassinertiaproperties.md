# ksCalcMassInertiaProperties - Получить объемные массово-центровочные характеристики тел вращения или выдавливания, заданных кривой или группой кривых

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления длин, расстояний, углов и МЦХ ](measures_fncts_common.html) |  Scroll [ [ [ ](ksdistancepntarc.html "К следующему разделу")](measures_fncts_common.html "На уровень выше")](kscalcinertiaproperties.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetcurveperimeter_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksCalcMassInertiaProperties](ksmathematic2d_kscalcmassinertiaproperties.html).

Синтаксис:

int ksCalcMassInertiaProperties (reference p,

MassInertiaParam * properties,

unsigned int bitVector,

double density,

double param);

Входные параметры:

p | \- указатель на кривую или группу кривых,  
---|---  
density | \- плотность тела (г/куб.мм),  
param | \- параметр тела (для тела вращения - угол раствора в градусах, для тела выдавливания - толщина),  
bitVector | \- структура параметров, определяющая [размерности длины, массы и типы деталей](mtypes.html).  
  
Выходные параметры:

properties | \- указатель на [структуру параметров для расчета МЦХ объемных тел](structmassinertiaparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

Кривые должны быть замкнутыми и представлять собой наружные и внутренние контура.

Подразделы:

(отсутствуют)
