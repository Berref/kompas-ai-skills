# NurbsParam - Структура параметров кривой NURBS

[Структуры параметров и константы](3d_define.html) > [Структуры параметров графических объектов ](bk1735830.html) |  Scroll [ [ [ ](structnurbspointparam.html "К следующему разделу")](bk1735830.html "На уровень выше")](structmathpointparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksNurbsParam](ksnurbsparam.html).

unsigned char | degree | порядок NURBS (степень полинома + 1), от 3 до 10,  
---|---|---  
unsigned char | close | признак замыкания сплайна (0 - незамкнутый, 1 - замкнутый),  
unsigned short | style | стиль линии,  
reference | pPoint | динамический массив точек сплайна (NurbsPointParam),  
reference | pKnot | динамический массив узлов сплайна,  
unsigned char | periodic | признак периодичности сплайна (0 - сплайн непериодический, 1 - сплайн периодический).  
  
[Системные стили линий...](lstyles.html)

[Структура параметров точки NURBS (NurbsPointParam)...](structnurbspointparam.html)

Примечание:

1\. Параметр periodic используется только для функции GetObjParam.

2\. Если для описания NURBS выбран вариант ALLPARAM или SHEET_ALLPARAM, то способ заполнения массивов pPoint и kPoint определяется значением параметра Close:

•Если Close=0 (NURBS замкнут) - параметры с разжатым узловым вектором,

•Если Close=1 (NURBS разомкнут) - параметры с зажатым узловым вектором.

Если для описания NURBS выбран вариант NURBS_CLAMPED_PARAM или NURBS_CLAMPED_SHEETPARAM, то, вне зависимости от значения параметра Close, возвращаются параметры с зажатым узловым вектором.

Подразделы:

(отсутствуют)
