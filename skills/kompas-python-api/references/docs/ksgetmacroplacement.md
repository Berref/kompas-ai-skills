# ksGetMacroPlacement - Получить точку привязки и угол поворота макроэлемента

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Работа с макроэлементами и библиотечными макроэлементами ](cm1919792.html) > [Функции работы с макроэлементами и библиотечными макроэлементами ](lib_macro_object_def.html) |  Scroll [ [ [ ](ksgetmacroplacementex.html "К следующему разделу")](lib_macro_object_def.html "На уровень выше")](ksgetmacroeditparamw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetMacroPlacement](ksdocument2d_ksgetmacroplacement.html).

Синтаксис:

int ksGetMacroPlacement (reference macro,

double *x,

double *y,

double *angl);

unsigned char sheetParam);

Входные параметры:

macro | \- указатель на макроэлемент (0 - редактируемый макроэлемент),  
---|---  
sheetParam | \- признак системы координат: 1 - координаты и угол заданы в СК макроэлемента, 0 - в СК вида.  
  
Выходные параметры:

x, y | \- координаты точки привязки макроэлемента,  
---|---  
angl | \- угол поворота макроэлемента от оси OX против часовой стрелки (в градусах).  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи,  
-1 | \- если у макроэлемента нет СК (не вызывалась функция [SetMacroPlacement](setmacroplacement.html)),  
  
Смотрите также:

Функция [SetMacroPlacement.](setmacroplacement.html)

Подразделы:

(отсутствуют)
