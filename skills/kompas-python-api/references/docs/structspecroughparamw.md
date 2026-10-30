# SpecRoughParamW - Структура параметров знака неуказанной шероховатости (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров объектов оформления чертежа ](bk1738515.html) |  Scroll [ [ [ ](structtechnicaldemandparam.html "К следующему разделу")](bk1738515.html "На уровень выше")](structspecroughparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksSpecRoughParam](ksspecroughparam.html).

unsigned short | style | номер стиля текста,  
---|---|---  
unsigned char | sign | тип знака (0 - вид обработки не устанавливается, 1 - обработка удалением слоя материала, 2 - обработка без удаления слоя материала),  
unsigned char | t | наличие знака в скобках (0 - нет знака, 1 - есть знак),  
wchar_t | s[TEXT_LENGTH] | текст.  
  
Примечание.

При использовании ANSI следует использовать структуру параметров [SpecRoughParam](structspecroughparam.html).

Подразделы:

(отсутствуют)
