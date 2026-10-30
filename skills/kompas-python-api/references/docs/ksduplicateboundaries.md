# ksDuplicateBoundaries - Получить временную группу контуров, задающих границы штриховки или заливки

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Составные объекты ](composit_obj_fncts_common.html) |  Scroll [ [ [ ](ksduplicateboundariesex.html "К следующему разделу")](composit_obj_fncts_common.html "На уровень выше")](contour.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksduplicateboundaries_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksDuplicateBoundaries](ksdocument2d_ksduplicateboundaries.html).

Синтаксис:

reference ksDuplicateBoundaries (reference p);

Входной параметр:

p | \- указатель на штриховку или заливку.  
---|---  
  
Возвращаемое значение:

указатель на временную группу контуров, задающих границы штриховки или заливки | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Функция устарела, рекомендуется вместо нее использовать функцию [ksDuplicateBoundariesEx](ksduplicateboundariesex.html)

Подразделы:

(отсутствуют)
