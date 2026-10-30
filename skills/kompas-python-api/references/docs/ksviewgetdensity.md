# ksViewGetDensity - Выбрать из диалога значение плотности

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления длин, расстояний, углов и МЦХ ](measures_fncts_common.html) |  Scroll [ [ [ ](ksviewgetdensityandmaterial.html "К следующему разделу")](measures_fncts_common.html "На уровень выше")](ksgetcurveperimeter.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksviewgetdensity_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksViewGetDensity](kompasobject_ksviewgetdensity.html).

Синтаксис:

double ksViewGetDensity (void * HWindow);

Входной параметр:

HWindow | \- дескриптор "родительского" окна или NULL.  
---|---  
  
Возвращаемое значение:

плотность (г/куб.мм) | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Плотность выбирается из системного файла плотностей graphic.dns.

Подразделы:

(отсутствуют)
