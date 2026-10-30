# ksHatchEx - Создать штриховку с заданными параметрами

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](ksinsertraster.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](kshatch.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksHatchByParam](ksdocument2d_kshatchbyparam.html).

Синтаксис:

reference ksHatchEx (HatchParamEx * par);

Входные параметры:

par | \- указатель на структуру параметров штриховки [HatchParamEx](structhatchparamex.html).  
---|---  
  
Возвращаемое значение:

указатель на штриховку | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Объекты границы штриховки лежат во временной группе pBoundaries.

2\. После выполнения функции ksHatchEx временная группа прекращает существование.

Подразделы:

(отсутствуют)
