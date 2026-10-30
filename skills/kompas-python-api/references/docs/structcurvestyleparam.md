# CurveStyleParam - Структура параметров стиля кривой

[Структуры параметров и константы](3d_define.html) > [Структуры параметров графических объектов ](bk1735830.html) |  Scroll [ [ [ ](structcurvestyleparamw.html "К следующему разделу")](bk1735830.html "На уровень выше")](structcurvepicture.html "К предыдущему разделу")  
---|---  
  
[Пример...](structcurvestyleparam_example.html)

Аналог данных параметров при использовании Automation - интерфейс [ksCurveStyleParam](kscurvestyleparam.html).

char | name[TEXT_LENGTH] | имя стиля,  
---|---|---  
unsigned long | color | цвет,  
double | paperWidth | толщина линии на бумаге ("толщина пера"),  
unsigned char | screenWidth | толщина линии на экране (в пикселах),  
unsigned char | curveType | набор полей, определяющих тип кривой (0 - сплошная, 1 - прерывистая 2 - прерывистая, содержащая картинки),  
reference | pattern | для прерывистой кривой - динамический массив параметров участков штриховой кривой,  
unsigned char | even | для прерывистой кривой: 1 - кривая всегда оканчивается штрихами 0 - кривая оканчивается "как получится".  
  
[Структура параметров CurvePattern...](structcurvepattern.html)

[Структура параметров CurvePatternEx...](structcurvepatternex.html)

[Параметры пера пользовательского стиля линии...](thicknesstypes.html)

Примечания:

1\. В качестве параметра pattern для прерывистой кривой используется динамический массив CURVE_STYLE, содержащий структуры параметров участков CurvePattern, а для прерывистой кривой, содержащей картинки, - динамический массив CURVE_STYLE_EX со структурами CurvePatternEx.

2\. Параметр curveType представляет собой набор полей, задающих тип кривой и толщину пера при отрисовке этой кривой.

3\. Например, если curveType = 1|LIKE_BASIC_LINE, то линия прерывистая с параметрами пера, как у системной основной линии.

При использовании Unicode следует использовать структуру параметров [CurveStyleParamW](structcurvestyleparamw.html)[.](structcurvestyleparamw.html)

Подразделы:

(отсутствуют)
