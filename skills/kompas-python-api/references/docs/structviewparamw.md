# ViewParamW - Структура параметров вида (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров документов ](bk1829760.html) |  Scroll [ [ [ ](bk1735830.html "К следующему разделу")](bk1829760.html "На уровень выше")](structviewparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksViewParam](ksviewparam.html).

unsigned short | state | состояние вида,  
---|---|---  
double | x,y | точка привязки вида,  
double | scale | масштаб вида,  
double | ang | угол поворота вида,  
unsigned long | color | цвет вида в активном состоянии  
wchar_t | name [TEXT_LENGTH] | имя вида.  
  
[Состояния видов и слоев...](layertypes.html)

Примечание.

1\. Параметры могут быть получены с помощью метода [GetObjParam](getobjparam.html) с параметром ALLPARAM.

2\. При использовании ANSI следует использовать структуру параметров [ViewParam.](structviewparam.html)

Подразделы:

(отсутствуют)
