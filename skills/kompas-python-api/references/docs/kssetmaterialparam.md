# ksSetMaterialParam - Установить параметры материала в чертеже

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Размеры и технологические обозначения ](cm1742473.html) > [Функции построения размеров /обозначений ](dims_signs_fncts_common.html) |  Scroll [ [ [ ](ksspecrough.html "К следующему разделу")](dims_signs_fncts_common.html "На уровень выше")](ksremoteelement.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksSetMaterialParam](ksdocument2d_kssetmaterialparam.html).

Синтаксис:

int ksSetMaterialParam (reference material, double density);

Входные параметры:

material | \- наименование материала, динамический массив строк текста (TEXT_LINE_ARR),  
---|---  
density | \- плотность (г/куб. мм).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
