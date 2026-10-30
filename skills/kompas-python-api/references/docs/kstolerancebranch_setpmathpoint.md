# SetpMathPoint - Установить указатель на интерфейс динамического массива точек "опоры" ksDynamicArray типа POINT_ARR

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Допуск формы и расположения поверхностей ](ch1724533.html) > [Интерфейс ksToleranceBranch ](kstolerancebranch.html) > [ksToleranceBranch - методы ](kstolerancebranch_methods.html) |  Scroll [ [ [ ](kstoleranceparam.html "К следующему разделу")](kstolerancebranch_methods.html "На уровень выше")](kstolerancebranch_init.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kstolerancebranch.html)

Синтаксис Automation:

BOOL SetpMathPoint(LPDISPATCH pMathPoint);

Входной параметр:

pMathPoint | \- указатель на интерфейс динамического массива математических точек [ksDynamicArray](ksdynamicarray.html) типа POINT_ARR.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечание:

Массив точек опоры состоит из начальной точки, принадлежащей таблице (ее в массив помещать не нужно, т.к. она определена свойством [tCorner)](kstolerancebranch_tcorner.html), точек излома (они могут отсутствовать) и конечной точки "опоры", указывающей на объект.

Смотрите также: [ksMathPointParam](ksmathpointparam.html)

Подразделы:

(отсутствуют)
