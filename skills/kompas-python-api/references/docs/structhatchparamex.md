# HatchParamEx - Расширенная структура параметров штриховки

[Структуры параметров и константы](3d_define.html) > [Структуры параметров графических объектов ](bk1735830.html) |  Scroll [ [ [ ](structhatchstyleparam.html "К следующему разделу")](bk1735830.html "На уровень выше")](structhatchparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksHatchParam](kshatchparam.html).

unsigned short | style | \- стиль штриховки,  
---|---|---  
double | ang | \- угол штриховки,  
double | step | \- шаг штриховки,  
double | width | \- ширина полосы штриховки (0 - штриховать всю область),  
double | x, y | \- координаты базовой точки (нужна только для отрисовки штриховки),  
reference | pBoundaries | \- временная группа - границы штриховки,  
unsigned long | color | \- Цвет, по умолчанию FREE_COLOR (0xff000000l),  
unsigned char | sheetAng | \- 0 - угол собственный (накатка); 1 - угол листовой (обычная штриховка).  
  
[Системные стили штриховок...](hstyles.html)

Примечание:

Параметр pBoundaries используется для функций GetObjParam и ksHatch.

Подразделы:

(отсутствуют)
