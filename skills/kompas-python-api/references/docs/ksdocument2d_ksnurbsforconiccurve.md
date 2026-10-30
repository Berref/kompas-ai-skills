# ksNurbsForConicCurve - Создать кривую NURBS по характеристическим точкам конического сечения

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Кривые Безье, NURBS, ломаные ](bt1730148.html) |  Scroll [ [ [ ](ksdocument2d_ksnurbsknot.html "К следующему разделу")](bt1730148.html "На уровень выше")](ksdocument2d_ksnurbs.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [NurbsForConicCurve](nurbsforconiccurve.html).

Синтаксис Automation:

long ksNurbsForConicCurve (LPDISPATCH xArr,

LPDISPATCH yArr,

short style);

Входные параметры:

xArr, yArr | \- указатели на интерфейсы динамических массивов [ksDynamicArray](ksdynamicarray.html) чисел типа DOUBLE_ARR,  
---|---  
style | \- стиль линии.  
  
[Системные стили линий...](lstyles.html)

Возвращаемое значение:

указатель на кривую NURBS | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
