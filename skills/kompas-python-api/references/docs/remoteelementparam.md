# RemoteElementParam - Структура параметров объекта "Выносной элемент"

[Структуры параметров и константы](3d_define.html) > [Структуры параметров объектов оформления чертежа ](bk1738515.html) |  Scroll [ [ [ ](structroughpar.html "К следующему разделу")](bk1738515.html "На уровень выше")](structqualityitemparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksRemoteElementParam](ksremoteelementparam.html).

unsigned short | style | стиль текста. если style = INDICATIN_TEXT_LINE_ARR, то pText - массив TEXT_LINE_ARR, если style = 0, то pText = TEXT_LINE_ARR,  
---|---|---  
long | signType | тип значка из перечислителя [LtRemoteElmSignType,](ltremoteelmsigntype.html)  
double | x | координаты центра выносного элемента,  
double | y  
double | width | ширина (для прямоугольника и скругленного прямоугольника),  
double | height | высота (для прямоугольника и скругленного прямоугольника),  
double | smooth | высота (для прямоугольника и скругленного прямоугольника),  
double | radius | радиус окружности (для окружности),  
double | shelfX; | координаты начала полки,  
double | shelfY  
int | shelfDir | направление полки: 1 - вправо; -1- влево, 2 - вверх, 3 - вниз,  
reference | pText | если style = INDICATIN_TEXT_LINE_ARR, то pText = TEXT_LINE_ARR - динамический массив строк текста, если style = 0, то pText = CHAR_STR_ARR или CHAR_STR_ARR_W - динамический массив строк символов текста шероховатости.  
  
Подразделы:

(отсутствуют)
