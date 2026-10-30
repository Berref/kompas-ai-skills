# SetMacroPlacement - Установить точку привязки и угол поворота макроэлемента

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Работа с макроэлементами и библиотечными макроэлементами ](cm1919792.html) > [Функции работы с макроэлементами и библиотечными макроэлементами ](lib_macro_object_def.html) |  Scroll [ [ [ ](cm1819576.html "К следующему разделу")](lib_macro_object_def.html "На уровень выше")](setmacroparam.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksSetMacroPlacement](ksdocument2d_kssetmacroplacement.html).

Синтаксис:

int SetMacroPlacement(reference macro,

double x,

double y,

double angl,

int relativ);

Входные параметры:

macro | \- указатель на макроэлемент (0 - редактируемый макроэлемент),  
---|---  
x, y | \- координаты точки привязки макроэлемента,  
angl | \- угол поворота макроэлемента от оси OX против часовой стрелки (в градусах),  
relativ | \- признак системы координат: 1 - координаты и угол заданы в СК макроэлемента, 0 - в СК вида.  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Смотрите также:

– Функции [GetMacroPlacement](getmacroplacement.html), [ksGetMacroPlacement](ksgetmacroplacement.html), [ksSetMacroPlacementEx](kssetmacroplacementex.html)

– [Рекомендации](mirrored_macro.html) по обеспечению корректного редактирования библиотекой макроэлементов, геометрия которых зеркально отражена, относительно исходного ее построения.

Подразделы:

(отсутствуют)
