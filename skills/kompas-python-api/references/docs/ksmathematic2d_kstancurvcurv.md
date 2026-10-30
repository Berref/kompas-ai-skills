# ksTanCurvCurv - Получить координаты точек касания прямых к двум кривым

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_kstanlineangcircle.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_kstancirclecircle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций -[ ksTanCurvCurv](kstancurvcurv.html).

Синтаксис Automation:

long ksTanCurvCurv (long p1,

long p2,

LPDISPATCH pointArr1,

LPDISPATCH pointArr2);

Входные параметры:

p1 | \- указатель на первую кривую,  
---|---  
p2 | \- указатель на вторую кривую.  
  
Выходные параметры:

pointArr1 | \- динамический массив [ksDynamicArray](ksdynamicarray.html) математических точек POINT_ARR на кривой p1,  
---|---  
pointArr2 | \- динамический массив математических точек [ksDynamicArray](ksdynamicarray.html) POINT_ARR на кривой p2.  
  
Возвращаемое значение:

1 | \- успешное завершение,  
---|---  
0 | \- построить касательную нельзя (кривые совпадают или одна кривая вложена в другую),  
-1 | \- первый объект не существует,  
-2 | \- второй объект не существует,  
-3 | \- кривые расположены в разных видах,  
-4 | \- не совпадают СК определения кривых (геометрическая и аннотационная),  
-5 | \- первый объект не является кривой,  
-6 | \- второй объект не является кривой,  
-7 | \- ошибка.  
  
Подразделы:

(отсутствуют)
