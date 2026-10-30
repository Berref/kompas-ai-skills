# InsertFragmentParamW - Структура параметров вставки фрагмента (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров графических объектов ](bk1735830.html) |  Scroll [ [ [ ](structlineparam.html "К следующему разделу")](bk1735830.html "На уровень выше")](structinsertfragmentparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksInsertFragmentParam](ksinsertfragmentparam.html).

PlacementParam | place | положение вставки фрагмента (PlacementParam),  
---|---|---  
unsigned char | insertType | тип вставки фрагмента (0 - взять в документ, 1 - внешней ссылкой, 3 - локальный фрагмент)  
unsigned char | multiLayer | признак размещения объектов фрагмента по слоям (0 - объекты на одном слое, 1 - объекты на разных слоях  
wchar_t | fileName [MAX_TEXT_LENGTH] | имя файла фрагмента или "\0" для локального фрагмента  
wchar_t | comment [MAX_TEXT_LENGTH | имя вставки  
  
[Структура параметров положения вставки PlacementParam...](structplacementparam.html)

Примечание.

При использовании ANSI следует использовать структуру параметров [InsertFragmentParam](structinsertfragmentparam.html).

Подразделы:

(отсутствуют)
