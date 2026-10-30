# InsertFragmentParamEx - Структура параметров вставки фрагмента (расширенная)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров библиотек ](bk1803365.html) |  Scroll [ [ [ ](structinsertfragmentparamexw.html "К следующему разделу")](bk1803365.html "На уровень выше")](bk1803365.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksInsertFragmentParam](ksinsertfragmentparam.html).

[PlacementParam](structplacementparam.html) | place | положение вставки фрагмента (PlacementParam),  
---|---|---  
unsigned char | insertType | тип вставки фрагмента (0 - взять в документ, 1 - внешней ссылкой, 3 - локальный фрагмент),  
unsigned char | multiLayer | признак размещения объектов фрагмента по слоям (0 - объекты на одном слое, 1 - объекты на разных слоях),  
char | fileName [MAX_TEXT_LENGTH] | имя файла фрагмента или "\0" для локального фрагмента,  
char | comment [MAX_TEXT_LENGTH] | имя вставки,  
unsigned char | scaleProjLinesSize | признак масштабирования длины выносных линий размеров: (1 - выносные линии масштабируются, 0 - выносные линии не масштабируются).  
  
Примечание.

При использовании Unicode следует использовать структуру параметров [InsertFragmentParamExW](structinsertfragmentparamexw.html).

Подразделы:

(отсутствуют)
