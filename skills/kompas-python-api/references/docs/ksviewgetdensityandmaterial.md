# ksViewGetDensityAndMaterial - Выбрать из диалога плотность и наименование материала

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Функции вычисления длин, расстояний, углов и МЦХ ](measures_fncts_common.html) |  Scroll [ [ [ ](ksviewgetdensityandmaterialw.html "К следующему разделу")](measures_fncts_common.html "На уровень выше")](ksviewgetdensity.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksViewGetDensityAndMaterial](kompasobject_ksviewgetdensityandmaterial.html).

Синтаксис:

double ksViewGetDensityAndMaterial (char * material, int sizeStr, void *HWindow);

Входные параметры:

HWindow | \- дескриптор "родительского" окна,  
---|---  
sizeStr | \- размер строки material.  
  
Выходные параметры:

material | \- наименование материала.  
---|---  
  
Возвращаемое значение:

плотность (г/куб.мм) | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Плотность выбирается из системного файла плотностей graphic.dns.

При использовании Unicode следует использовать функцию [ksViewGetDensityAndMaterialW](ksviewgetdensityandmaterialw.html).

Подразделы:

(отсутствуют)
