# HatchLineParamW - Структура параметров линии штриховки (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров графических объектов ](bk1735830.html) |  Scroll [ [ [ ](structhatchparam.html "К следующему разделу")](bk1735830.html "На уровень выше")](structhatchlineparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksHatchLineParam](kshatchlineparam.html).

double | x, y | точка привязки линии,  
---|---|---  
double | dx, dy | смещение для следующей линии; dy должен быть отличен от нуля!  
double | ang | угол наклона линии,  
unsigned char | typeCurvStyle | признак стиля линии (0 - системный 1 - пользовательский),  
unsigned short | style | системный стиль линии,  
[CurveStyleParamW](structcurvestyleparamw.html) | curPar | структура параметров пользовательского стиля линии.  
  
[Системные стили линий...](lstyles.html)

Примечание.

При использовании ANSI следует использовать структуру параметров [HatchLineParam](structhatchlineparam.html)[.](structhatchlineparam.html)

Подразделы:

(отсутствуют)
