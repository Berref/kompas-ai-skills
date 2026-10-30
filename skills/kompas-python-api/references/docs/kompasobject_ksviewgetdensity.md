# ksViewGetDensity - Выбрать из диалога плотность

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksviewgetdensityandmaterial.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_kssetsysoptions.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksViewGetDensity](ksviewgetdensity.html).

Синтаксис Automation:

double ksViewGetDensity (long HWindow);

Входной параметр:

HWindow | \- дескриптор "родительского" окна или NULL.  
---|---  
  
Возвращаемое значение:

плотность (г/куб.мм) | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Плотность выбирается из системного [файла плотностей graphic.dns](sys_density_file.html).

Подразделы:

(отсутствуют)
