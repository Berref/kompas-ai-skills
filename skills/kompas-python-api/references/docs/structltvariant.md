# LtVariant - Структура параметров для хранения данных некоторого типа

[Структуры параметров и константы](3d_define.html) > [Структуры параметров системы ](bk1803366.html) |  Scroll [ [ [ ](structltvariantex.html "К следующему разделу")](bk1803366.html "На уровень выше")](structconstraintparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksLtVariant](ksltvariant.html).

[LtVariantType](ltvarianttype.html) | vType | тип хранимых данных, |  |   
---|---|---|---|---  
short | colVisible | для спецификации: 1 - видимая колонка, 0 - невидимая колонка, |  |   
short | sortKey | ключ сортировки для колонки спецификации (0 - сортировки нет), |  |   
short | wReserved3 | параметр зарезервирован для дальнейшего использования, |  |   
char | chVal | символ, | ltv_Char | 1  
unsigned char | ucVal | байт, | ltv_Uchar | 2  
int | iVal | целое число, | ltv_Int | 3  
unsigned int | uiVal | беззнаковое целое число, | ltv_Uint | 4  
long | lVal | длинное целое число, | ltv_Long | 5  
float | fVal | вещественное число, | ltv_Float | 6  
double | dVal | двойное число, | ltv_Double | 7  
char | strVal [MAX_TEXT_LENGTH] | строка, | ltv_Str | 8  
short | shVal | короткое целое число. | ltv_Short | 10  
  
Примечание.

При использовании Unicode следует использовать структуру параметров [LtVariantEx](structltvariantex.html).

Подразделы:

(отсутствуют)
