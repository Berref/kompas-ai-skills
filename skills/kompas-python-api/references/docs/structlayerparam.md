# LayerParam - Структура параметров слоя

[Структуры параметров и константы](3d_define.html) > [Структуры параметров документов ](bk1829760.html) |  Scroll [ [ [ ](structlayerparamw.html "К следующему разделу")](bk1829760.html "На уровень выше")](structdocumentparamw.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksLayerParam](kslayerparam.html).

unsigned short | state | состояние слоя,  
---|---|---  
unsigned long | color | цвет слоя в активном состоянии,  
char | name [TEXT_LENGTH] | имя слоя.  
  
[Состояния видов и слоев...](layertypes.html)

Примечание.

При использовании Unicode следует использовать структуру параметров [LayerParamW](structlayerparamw.html).

Подразделы:

(отсутствуют)
