# TextItemFont - Структура параметров шрифта компоненты строки текста

[Структуры параметров и константы](3d_define.html) > [Структуры параметров текста ](bk1742729.html) |  Scroll [ [ [ ](structtextitemfontw.html "К следующему разделу")](bk1742729.html "На уровень выше")](structtextlineparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksTextItemFont](kstextitemfont.html).

char | fontName [MAX_TEXT_LENGTH] | имя шрифта,  
---|---|---  
double | height | высота шрифта (в миллиметрах),  
double | ksu | коэффициент сужения символов,  
unsigned | long color | цвет символов,  
unsigned int | bitVector | битовый вектор, определяющий начертание символов (наклон, толщину, подчеркивание, тип составной части - дробь, отклонение и т.д.).  
  
Примечание.

При использовании Unicode следует использовать структуру параметров [TextItemFontW](structtextitemfontw.html).

Подразделы:

(отсутствуют)
