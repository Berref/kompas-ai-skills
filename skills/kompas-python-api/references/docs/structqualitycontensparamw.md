# QualityContensParamW - Структура параметров квалитета (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров объектов оформления чертежа ](bk1738515.html) |  Scroll [ [ [ ](structqualityitemparam.html "К следующему разделу")](bk1738515.html "На уровень выше")](structqualitycontensparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksQualityContensParam](ksqualitycontensparam.html).

[LtQualSystem](ltqualsystem.html) | systemQuality | система квалитета,  
---|---|---  
[LtQualDir](ltqualdir.html) | kindQuality | тип квалитета,  
wchar_t | name[MAX_TEXT_LENGTH] | поле допуска,  
reference | pQualityItems | массив интервалов.  
  
Примечание.

При использовании ANSI следует использовать структуру параметров [QualityContensParam](structqualitycontensparam.html).

Подразделы:

(отсутствуют)
