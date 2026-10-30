# ksDuplicateBoundariesEx - Получить копию границы штриховки или заливки во временной группе

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Составные объекты ](composit_obj_fncts_common.html) |  Scroll [ [ [ ](endobj.html "К следующему разделу")](composit_obj_fncts_common.html "На уровень выше")](ksduplicateboundaries.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksDuplicateBoundaries](ksdocument2d_ksduplicateboundaries.html).

Синтаксис:

reference ksDuplicateBoundariesEx (reference p, unsigned char systemCoord);

Входной параметр:

p | \- указатель на штриховку или заливку.  
---|---  
systemCoord | 1 - в системе координат листа, 0 - в системе координат текущего вида.  
  
Возвращаемое значение:

указатель на временную группу контуров, задающих границы штриховки или заливки | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
