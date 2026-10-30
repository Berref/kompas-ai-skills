# InsertFragmentParam - Структура параметров вставки фрагмента

[Структуры параметров и константы](3d_define.html) > [Структуры параметров графических объектов ](bk1735830.html) |  Scroll [ [ [ ](structinsertfragmentparamw.html "К следующему разделу")](bk1735830.html "На уровень выше")](structhotpointdescription1.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksInsertFragmentParam](ksinsertfragmentparam.html).

PlacementParam | place | положение вставки фрагмента (PlacementParam),  
---|---|---  
unsigned char | insertType | тип вставки фрагмента (0 - взять в документ, 1 - внешней ссылкой, 3 - локальный фрагмент),  
unsigned char | multiLayer | признак размещения объектов фрагмента по слоям (0 - объекты на одном слое, 1 - объекты на разных слоях,  
char | fileName [MAX_TEXT_LENGTH] | имя файла фрагмента или "\0" для локального фрагмента,  
char | comment [MAX_TEXT_LENGTH | имя вставки.  
  
[Структура параметров положения вставки PlacementParam...](structplacementparam.html)

Примечание.

При использовании Unicode следует использовать структуру параметров [InsertFragmentParamW](structinsertfragmentparamw.html).

Подразделы:

(отсутствуют)
