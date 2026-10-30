# ksMakeEncloseContours - Определить группу объектов, охватывающих заданную точку

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Математические функции ](math_fncts_common.html) |  Scroll [ [ [ ](kspointfrommtr.html "К следующему разделу")](math_fncts_common.html "На уровень выше")](kslinepointtangentcurve.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksmakeenclosecontours_kshatch_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksMakeEncloseContours](ksdocument2d_ksmakeenclosecontours.html).

Синтаксис:

reference ksMakeEncloseContours (reference gr, double x, double y);

Входные параметры:

gr | \- временная группа или 0, если требуются контуры в текущем виде,  
---|---  
x, y | \- координаты точки внутри охватываемых контуров.  
  
Возвращаемое значение:

указатель на временную группу контуров | \- в случае удачного завершения,  
---|---  
0 | \- если контуров не нашлось или в случае неудачи.  
  
Подразделы:

(отсутствуют)
