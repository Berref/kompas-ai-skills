# DimensionsOptions - Структура параметров для определения настроек размеров

[Структуры параметров и константы](3d_define.html) > [Структуры параметров размеров ](bk1838215.html) |  Scroll [ [ [ ](structdimensionpartsparam.html "К следующему разделу")](bk1838215.html "На уровень выше")](structdimtext.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksDimensionsOptions](ksdimensionsoptions.html).

double | proLineExtension | выход выносных линий за размерную,  
---|---|---  
double | textDistanceFromDimLine | расстояние от размерной линии до текста,  
double | textDistanceFromProLine | расстояние от выносных линий до текста,  
double | dimLineExtension | выход размерной линии за текст,  
double | arrowLength | длина стрелки размера,  
unsigned short | style | стиль текста,  
unsigned char | decimalsCount | количество знаков после запятой (от 0 до 9),  
int | anglePrecisionLevel | точность углового размера: 0 - градусы, 1- минуты, 2- секунды,  
int | hiddenToleranceNumber | максимальный номер показываемого квалитета (от 1 до 17) -1 - показ квалитета не включен.  
  
Подразделы:

(отсутствуют)
