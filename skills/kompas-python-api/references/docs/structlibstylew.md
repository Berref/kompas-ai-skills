# LibStyleW - Структура параметров для подключения стиля из библиотеки (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров библиотек ](bk1803365.html) |  Scroll [ [ [ ](libtoolbarsettings.html "К следующему разделу")](bk1803365.html "На уровень выше")](structlibstyle.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksLibStyle](kslibstyle.html).

wchar_t | fileName [MAX_TEXT_LENGTH] | имя файла библиотеки,  
---|---|---  
int | styleNumber | номер стиля в библиотеке,  
unsigned char | typeAllocation | тип размещения стиля в документе (0 - телом; 1 - ссылкой на библиотеку)  
  
Примечание.

При использовании ANSI следует использовать структуру параметров[ LibStyle](structlibstyle.html).

Подразделы:

(отсутствуют)
