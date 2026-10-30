# _Bezier - Создать кривую Безье по массиву точек (узлов кривой Безье)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Кривые Безье, Nurbs, ломаные ](nurbs_fncts_common.html) |  Scroll [ [ [ ](bezierpoint.html "К следующему разделу")](nurbs_fncts_common.html "На уровень выше")](bezier.html "К предыдущему разделу")  
---|---  
  
[Пример...](bezier_bezier_example.html)

Синтаксис:

reference _Bezier (BezierPointParam *par,

int CountPoints,

int closed,

unsigned int style);

Входные параметры:

par | \- массив точек (узлов кривой Безье - [BezierPointParam](structbezierpointparam.html)), определяющих кривую.  
---|---  
CountPoints | \- количество точек в массиве,  
closed | \- признак замыкания сплайна: 0 - незамкнутый, 1 - замкнутый,  
style | \- стиль линии.  
  
[Системные стили линий...](lstyles.html)

Возвращаемое значение:

указатель на кривую Безье | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
