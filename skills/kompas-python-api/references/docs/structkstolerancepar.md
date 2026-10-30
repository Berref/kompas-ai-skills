# ksTolerancePar - Структура параметров обозначения допуска формы

[Структуры параметров и константы](3d_define.html) > [Структуры параметров объектов оформления чертежа ](bk1738515.html) |  Scroll [ [ [ ](structleaderparam.html "К следующему разделу")](bk1738515.html "На уровень выше")](structcutlineparamw.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksToleranceParam](kstoleranceparam.html).

unsigned char | tBase | число от 1 до 8, определяющее [возможные положения базовой точки,](tbaseparam.html)  
---|---|---  
unsigned short | style | стиль текста (0 - стиль по умолчанию),  
double | x, y | координаты базовой точки,  
unsigned char | type | ориентация таблицы допуска (0 - горизонтально, 1- вертикально),  
reference | branchArr | динамический массив опор (структур [ToleranceBranch](structtolerancebranch.html)),  
  
Подразделы:

(отсутствуют)
