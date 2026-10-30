# TextItemFontW - Структура параметров шрифта компоненты строки текста (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров текста ](bk1742729.html) |  Scroll [ [ [ ](structtextitemparam.html "К следующему разделу")](bk1742729.html "На уровень выше")](structtextitemfont.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksTextItemFont](kstextitemfont.html).

wchar_t | fontName [MAX_TEXT_LENGTH] | имя шрифта,  
---|---|---  
double | height | высота шрифта (в миллиметрах),  
double | ksu | коэффициент сужения символов,  
unsigned | long color | цвет символов,  
unsigned int | bitVector | битовый вектор, определяющий начертание символов (наклон, толщину, подчеркивание, тип составной части - дробь, отклонение и т.д.).  
  
Примечание.

При использовании ANSI следует использовать структуру параметров [TextItemFont](structtextitemfont.html).

Подразделы:

(отсутствуют)
