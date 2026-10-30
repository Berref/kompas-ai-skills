# ksViewGetDensityAndMaterial - Выбрать из диалога плотность и наименование материала

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_loaddsk.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksviewgetdensity.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksViewGetDensityAndMaterial](ksviewgetdensityandmaterial.html).

Синтаксис Automation:

BSTR ksViewGetDensityAndMaterial (double *density, long HWindow);

Входные параметры:

Hwindow | \- дескриптор окна.  
---|---  
  
Выходные параметры:

density | \- плотность (г/куб.мм)  
---|---  
  
Возвращаемое значение:

Строка с обозначением материала | \- в случае успешного завершения,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание:

Плотность выбирается из системного[ файла плотностей graphic.dns](sys_density_file.html).

Подразделы:

(отсутствуют)
