# TextStyleParamW - Структура параметров стиля текста (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров текста ](bk1742729.html) |  Scroll [ [ [ ](bk1742730.html "К следующему разделу")](bk1742729.html "На уровень выше")](structtextstyleparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksTextStyleParam](kstextstyleparam.html).

wchar_t | name [TEXT_LENGTH] | имя стиля,  
---|---|---  
double | height | высота текста шрифта,  
double | ksu | коэффициент сужения символов,  
double | step | шаг строк,  
wchar_t | fontName [TEXT_LENGTH] | имя шрифта,  
unsigned long | color | цвет,  
unsigned char | align | выравнивание (0 - влево, 1 - по центру, 2 - вправо, 3 - на всю ширину,  
unsigned char | bold | начертание символов (0 - не утолщенные, 1 - утолщенные),  
unsigned char | italic | начертание символов (0 - без наклона, 1 - с наклоном),  
unsigned char | underline | подчеркивание (0 - без подчеркивания, 1 - с подчеркиванием),  
double | posKS | отступ красной строки (в миллиметрах),  
double | stepParPre | интервал перед текстом,  
double | stepParPst | интервал после текста,  
double | leftEdge | отступ текста слева,  
double | rightEdge | отступ текста справа.  
  
Примечание.

При использовании ANSI следует использовать структуру параметров [TextStyleParam](structtextstyleparam.html).

Подразделы:

(отсутствуют)
