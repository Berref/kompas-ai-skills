# GetPKnot - Получить динамический массив узлов сплайна ksDynamicArray типа DOUBLE_ARR

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров графических примитивов ](cd1743949.html) > [NURBS ](cd1751192.html) > [Кривая NURBS (Интерфейс ksNurbsParam) ](ksnurbsparam.html) > [ksNurbsParam - методы ](ksnurbsparam_methods.html) |  Scroll [ [ [ ](ksnurbsparam_getppoint.html "К следующему разделу")](ksnurbsparam_methods.html "На уровень выше")](ksnurbsparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbsparam.html)

Синтаксис Automation:

LPDISPATCH GetPKnot();

Возвращаемое значение:

| \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) узлов сплайна типа DOUBLE_ARR.  
---|---  
  
Примечания:

Если для описания NURBS выбран вариант ALLPARAM или SHEET_ALLPARAM, то способ заполнения массива точек определяется значением параметра Close:

•Если Close=0 (NURBS замкнут) - параметры с разжатым узловым вектором,

•Если Close=1 (NURBS разомкнут) - параметры с зажатым узловым вектором.

Если для описания NURBS выбран вариант NURBS_CLAMPED_PARAM или NURBS_CLAMPED_SHEETPARAM, то, вне зависимости от значения параметра Close, возвращаются параметры с зажатым узловым вектором.

Подразделы:

(отсутствуют)
