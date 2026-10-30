# ksCalcInertiaProperties - Получить плоские массово-центровочные характеристики кривой или группы кривых

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_kscalcmassinertiaproperties.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_ksatand.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksCalcInertiaProperties](kscalcinertiaproperties.html).

Синтаксис Automation:

long ksCalcInertiaProperties (long p,

LPDISPATCH properties,

short dimension);

Входные параметры:

p | \- указатель на кривую или группу кривых,  
---|---  
dimension | \- размерность длины.  
  
Выходные параметры:

properties | \- указатель на интерфейс параметров для расчета МЦХ [ksInertiaParam](ksinertiaparam.html).  
---|---  
  
[Размерности длины...](lentypes.html)

Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Примечание:

Кривые должны быть замкнутыми и представлять собой наружные и внутренние контура.

Подразделы:

(отсутствуют)
