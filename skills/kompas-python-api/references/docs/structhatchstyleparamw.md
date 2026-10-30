# HatchStyleParamW - Структура параметров стиля штриховки (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров графических объектов ](bk1735830.html) |  Scroll [ [ [ ](structhotpointdescription.html "К следующему разделу")](bk1735830.html "На уровень выше")](structhatchstyleparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksHatchStyleParam](kshatchstyleparam.html).

wchar_t | name [TEXT_LENGTH] | имя стиля штриховки,  
---|---|---  
double | step | шаг штриховки по умолчанию,  
double | ang | угол наклона,  
MathPointParam | refPoint | базовая точка штриховки,  
double | width | ширина полосы штриховки,  
unsigned long | color | цвет штриховки (по умолчанию FREE_COLOR (0xff000000),  
unsigned char | mayChangeAngle | признак, показывающий, разрешено ли менять угол наклона штриховки,  
unsigned char | mayChangeWidth | признак, показывающий, разрешено ли менять ширину полосы штриховки,  
unsigned char | mayChangeSpace | признак, показывающий, разрешено ли менять шаг (масштаб) штриховки,  
unsigned char | isScalable | признак изменения расстояния между линиями штриховки (1 - по масштабу, 0 - по шагу),  
reference | arrLineParam | массив структур параметров линий, участвующих в штриховке [HatchLineParam.](structhatchlineparam.html)  
  
[Структура параметров MathPointParam...](structmathpointparam.html)

Примечание.

При использовании ANSI следует использовать структуру параметров [HatchStyleParam](structhatchstyleparam.html).

Подразделы:

(отсутствуют)
