# SetPPattern - Установить (для прерывистой кривой) указатель на динамический массив параметров участков штриховой кривой ksDynamicArray типа CURVE_PATTERN_ARR или CURVE_PATTERN_ARR_EX

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров стилей объектов ](cf1711377.html) > [Стиль линии ](cf1753270.html) > [Стиль линии (Интерфейс ksCurveStyleParam) ](kscurvestyleparam.html) > [ksCurveStyleParam - методы ](kscurvestyleparam_methods.html) |  Scroll [ [ [ ](kscurvepattern.html "К следующему разделу")](kscurvestyleparam_methods.html "На уровень выше")](kscurvestyleparam_init.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurvestyleparam.html)

Синтаксис Automation:

BOOL SetPPattern (LPDISPATCH pPattern);

Входной параметр:

pPattern | \- указатель на динамический массив [ksDynamicArray](ksdynamicarray.html) типа CURVE_PATTERN_ARR или CURVE_PATTERN_ARR_EX.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечание:

Типу массива CURVE_PATTERN_ARR соответствует интерфейс [ksCurvePattern](kscurvepattern.html).

Типу массива CURVE_PATTERN_ARR_EX соответствует интерфейс [ksCurvePatternEx](kscurvepatternex.html).

Смотрите также: [ksCurveStyleParam::curveType](kscurvestyleparam_curvetype.html)

Подразделы:

(отсутствуют)
