# ksCalcMassInertiaProperties - Получить объемные массово-центровочные характеристики тел вращения или выдавливания, заданных кривой или группой кривых

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_kscosd.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_kscalcinertiaproperties.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksCalcMassInertiaProperties](kscalcmassinertiaproperties.html).

Синтаксис Automation:

long ksCalcMassInertiaProperties (long p,

LPDISPATCH properties,

double density,

double param);

Входные параметры:

p | \- указатель на кривую или группу кривых,  
---|---  
density | \- плотность тела (г/куб.мм),  
param | \- параметр тела (для тела вращения - угол раствора в градусах, для тела выдавливания - толщина).  
  
Выходные параметры:

properties | \- указатель на интерфейс параметров для расчета массово-центровочных характеристик [ksMassInertiaParam](ksmassinertiaparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Кривые должны быть замкнутыми и представлять собой наружные и внутренние контура.

2\. Тип тела (тело вращения или выдавливания) устанавливается перед вызовом метода в интерфейсе ksMassInertiaParam.

Подразделы:

(отсутствуют)
