# LtVariantEx - Структура параметров для хранения данных некоторого типа (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров системы ](bk1803366.html) |  Scroll [ [ [ ](structrequestinfo.html "К следующему разделу")](bk1803366.html "На уровень выше")](structltvariant.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksLtVariant](ksltvariant.html).

[LtVariantType](ltvarianttype.html) | vType | тип хранимых данных, |  |   
---|---|---|---|---  
short | colVisible | для спецификации: 1 - видимая колонка, 0 - невидимая колонка, |  |   
short | sortKey | ключ сортировки для колонки спецификации (0 - сортировки нет), |  |   
short | wReserved3 | параметр зарезервирован для дальнейшего использования, |  |   
union |  |  |  |   
char | chVal | символ, | ltv_Char | 1  
unsigned char | ucVal | байт, | ltv_Uchar | 2  
int | iVal | целое число, | ltv_Int | 3  
unsigned int | uiVal | беззнаковое целое число, | ltv_Uint | 4  
long | lVal | длинное целое число, | ltv_Long | 5  
float | fVal | вещественное число, | ltv_Float | 6  
double | dVal | двойное число, | ltv_Double | 7  
wchar_t | strVal [MAX_TEXT_LENGTH] | строка, | ltv_Str | 8  
short | shVal | короткое целое число. | ltv_Short | 10  
wchar_t | wstrVal[MAX_TEXT_LENGTH] | строка | ltv_WStr | 11  
  
Примечание.

При использовании ANSI следует использовать структуру параметров [LtVariant](structltvariant.html).

Подразделы:

(отсутствуют)
