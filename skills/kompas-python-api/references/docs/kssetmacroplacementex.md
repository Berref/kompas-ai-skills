# ksSetMacroPlacementEx - Установить точку привязки и угол поворота макроэлемента

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Работа с макроэлементами и библиотечными макроэлементами ](cm1919792.html) > [Функции работы с макроэлементами и библиотечными макроэлементами ](lib_macro_object_def.html) |  Scroll [ [ [ ](kssetmacrowaitdblclickedit.html "К следующему разделу")](lib_macro_object_def.html "На уровень выше")](kssetmacroparamw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksSetMacroPlacementEx](ksdocument2d_kssetmacroplacementex.html).

Синтаксис:

int ksSetMacroPlacementEx( reference macro,

double x,

double y,

double angl,

int relative,

unsigned char mirrorSymmetry );

Входные параметры:

macro | \- указатель на макроэлемент (0 - редактируемый макроэлемент),  
---|---  
x, y | \- точка начала координат макроэлемента,  
angl | \- угол поворота оcи X,  
relative | \- признак системы координат: 1 - координаты и угол заданы в СК макроэлемента, 0 - в СК вида,  
mirrorSymmetry | \- флаг зеркальной симметрии объекта.  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Смотрите также:

1\. Функции [GetMacroPlacement](getmacroplacement.html), [ksGetMacroPlacement](ksgetmacroplacement.html).

2\. [Рекомендации ](mirrored_macro.html)по обеспечению корректного редактирования библиотекой макроэлементов, геометрия которых зеркально отражена относительно исходного ее построения.

Примечание:

Функция позволяет установить СК макроэлемента либо в СК вида, либо смещением относительно СК макроэлемента.

Подразделы:

(отсутствуют)
