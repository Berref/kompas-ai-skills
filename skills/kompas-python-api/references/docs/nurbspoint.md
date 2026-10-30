# NurbsPoint - Создать узел NURBS

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Кривые Безье, Nurbs, ломаные ](nurbs_fncts_common.html) |  Scroll [ [ [ ](tanlineangcurve.html "К следующему разделу")](nurbs_fncts_common.html "На уровень выше")](nurbsforconiccurve.html "К предыдущему разделу")  
---|---  
  
[Пример...](nurbs_nurbspoint_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksNurbsPoint](ksdocument2d_ksnurbspoint.html).

Синтаксис:

int NurbsPoint (NurbsPointParam *par);

Входной параметр:

par | \- указатель на [структуру параметров узла NURBS...](structnurbspointparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Узлы кривой определяются следующими далее функциями [Point](point.html) или [NurbsPoint](nurbspoint.html). Описание кривой завершается функцией [EndObj](endobj.html), возвращающей указатель на созданную кривую.

Подразделы:

(отсутствуют)
