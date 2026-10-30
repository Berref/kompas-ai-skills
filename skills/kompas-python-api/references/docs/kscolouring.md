# ksColouring - Создать фоновую заливку цветом

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](kscolouringex.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](hatchex.html "К предыдущему разделу")  
---|---  
  
[Пример...](kscolouring_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksColouring](ksdocument2d_kscolouring.html).

Синтаксис:

int ksColouring (unsigned long color);

Входной параметр:

color | \- цвет заливки.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Заливка - составной объект. Объекты вида, вводимые между операторами ksColouring и [EndObj](endobj.html), принадлежат заливке и образуют ее границу. EndObj возвращает указатель на заливку.

2\. Если color = -1 или 0xFFFFFFFF - создается заливка цветом фона документа.

Подразделы:

(отсутствуют)
