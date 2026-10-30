# LayerParamW - Структура параметров слоя (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров документов ](bk1829760.html) |  Scroll [ [ [ ](overlapobjectoptions.html "К следующему разделу")](bk1829760.html "На уровень выше")](structlayerparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksLayerParam](kslayerparam.html).

unsigned short | state | состояние слоя,  
---|---|---  
unsigned long | color | цвет слоя в активном состоянии,  
wchar_t | name [TEXT_LENGTH] | имя слоя.  
  
[Состояния видов и слоев...](layertypes.html)

Примечание.

При использовании ANSI следует использовать структуру параметров [LayerParam](structlayerparam.html).

Подразделы:

(отсутствуют)
