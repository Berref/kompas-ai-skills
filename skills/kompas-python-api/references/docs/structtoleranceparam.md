# ToleranceParam - Структура параметров обозначения допуска формы

[Структуры параметров и константы](3d_define.html) > [Структуры параметров объектов оформления чертежа ](bk1738515.html) |  Scroll [ [ [ ](structviewpointerparam.html "К следующему разделу")](bk1738515.html "На уровень выше")](structtolerancebranch.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksToleranceParam](kstoleranceparam.html).

Замечание:

Структура устарела. Функции [GetObjParam](getobjparam.html) и [SetObjParam](setobjparam.html) с ней больше не работают.Рекомендуется использовать [ksTolerancePar](structkstolerancepar.html).

unsigned char | tBase | число от 1 до 8, определяющее [возможные положения базовой точки,](tbaseparam.html)  
---|---|---  
unsigned short | style | стиль текста (0 - стиль по умолчанию),  
double | x, y | координаты базовой точки,  
unsigned char | type | ориентация таблицы допуска (0 - горизонтально, 1- вертикально),  
ToleranceBranch | branch1 | структура параметров первой "опоры",  
ToleranceBranch | branch2 | структура параметров второй "опоры".  
  
[Структура параметров ToleranceBranch...](structtolerancebranch.html)

Примечания:

Чтобы вторая "опора" отсутствовала, ее параметр arrowType должен быть равен нулю.

Подразделы:

(отсутствуют)
