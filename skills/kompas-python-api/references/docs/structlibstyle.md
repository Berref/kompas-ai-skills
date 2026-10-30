# LibStyle - Структура параметров для подключения стиля из библиотеки

[Структуры параметров и константы](3d_define.html) > [Структуры параметров библиотек ](bk1803365.html) |  Scroll [ [ [ ](structlibstylew.html "К следующему разделу")](bk1803365.html "На уровень выше")](structinsertfragmentparamexw.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksLibStyle](kslibstyle.html).

char | fileName [MAX_TEXT_LENGTH] | имя файла библиотеки,  
---|---|---  
int | styleNumber | номер стиля в библиотеке,  
unsigned char | typeAllocation | тип размещения стиля в документе (0 - телом; 1 - ссылкой на библиотеку).  
  
Примечание.

При использовании Unicode следует использовать структуру параметров [LibStyleW](structlibstylew.html).

Подразделы:

(отсутствуют)
