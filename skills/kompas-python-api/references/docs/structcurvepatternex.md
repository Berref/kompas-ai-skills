# CurvePatternEx - Структура параметров участка штриховой кривой (расширенная)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров графических объектов ](bk1735830.html) |  Scroll [ [ [ ](structcurvepatternexw.html "К следующему разделу")](bk1735830.html "На уровень выше")](structcurvepattern.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksCurvePatternEx](kscurvepatternex.html).

double | visibleSeg | длина видимого участка,  
---|---|---  
double | invisibleSeg | длина невидимого участка,  
double | dx, dy | положение базовой точки ("нуля") картинки относительно начала образца,  
unsigned char | pictureType | тип картинки (0 - картинка в виде массивов ломаных линий, 1 - картинка в виде фрагмента),  
[CurvePicture](structcurvepicture.html) | picture | структура параметров картинки, состоящей из ломаных линий,  
char | frwName[TEXT_LENGTH] | имя фрагмента-источника картинки.  
  
Примечания:

1\. Какой из параметров - picture или frwName используется, определяется значением параметра pictureType.

2\. Картинка в виде фрагмента используется только в функции AddStyle (при создании стиля).

3\. При использовании Unicode следует использовать структуру параметров [CurvePatternExW](structcurvepatternexw.html)[.](structcurvepatternexw.html)

Подразделы:

(отсутствуют)
