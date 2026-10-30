# ksNurbsKnot - Создать узел NURBS-кривой

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Кривые Безье, NURBS, ломаные ](bt1730148.html) |  Scroll [ [ [ ](ksdocument2d_ksnurbspoint.html "К следующему разделу")](bt1730148.html "На уровень выше")](ksdocument2d_ksnurbsforconiccurve.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksNurbsKnot](ksnurbsknot.html).

Синтаксис Automation:

long ksNurbsKnot (double knot);

Входной параметр:

knot | \- узел кривой NURBS.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Метод предназначен для считывания форматов обмена, в частности, DXF.

Для создания кривой NURBS массив узлов (узловой вектор) задавать не обязательно. Но если он задан, то должен подчиняться следующим правилам:

1\. Узловой вектор не должен быть убывающим.

2\. Количество узлов (knotCount) должно быть:

•для разомкнутого сплайна knotCount= degree + pointCount;

•для замкнутого сплайна knotCount= degree + pointCount + ( degree -1);

где:

degree - степень сплайна,

pointCount - количество точек.

Подразделы:

(отсутствуют)
