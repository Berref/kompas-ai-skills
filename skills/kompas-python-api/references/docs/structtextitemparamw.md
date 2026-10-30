# TextItemParamW - Структура параметров компоненты строки текста (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров текста ](bk1742729.html) |  Scroll [ [ [ ](structtextparam.html "К следующему разделу")](bk1742729.html "На уровень выше")](structtextitemparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksTextItemParam](kstextitemparam.html).

int | tip | SPECIAL_SYMBOL или FONT_SYMBOL, или FRACTION_TYPE, или SUM_TYPE, или 0.  
---|---|---  
TextItemFont | font | параметры шрифта компоненты строки текста,  
wchar_t | s [TEXT_LENGTH] | массив символов компоненты строки текста,  
unsigned int | iSNumb | номер спецсимвола или символа из произвольного шрифта или тип отрисовки дроби, или выражения типа суммы, или 0.  
  
[Структура параметров TextItemFontW...](structtextitemfontw.html)

Примечание.

1\. Таблица спецсимволов размещена в файле SDK\NumbSymb.frw.

2\. При использовании ANSI следует использовать структуру параметров [TextItemParam](structtextitemparam.html).

Подразделы:

(отсутствуют)
