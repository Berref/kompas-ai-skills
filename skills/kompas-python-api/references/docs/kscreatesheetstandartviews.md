# ksCreateSheetStandartViews - Создать стандартные ассоциативные виды

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с видами ](cm1826821.html) > [Функции работы с видами ](views_fncts_common.html) |  Scroll [ [ [ ](kscreatesheetstandartviewsw.html "К следующему разделу")](views_fncts_common.html "На уровень выше")](kscreatesheetsectionvieww.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksCreateSheetStandartViews](ksdocument2d_kscreatesheetstandartviews.html).

Синтаксис:

int ksCreateSheetStandartViews (AssociationViewParam *par,

unsigned int bitVector,

double dx,

double dy);

Входные параметры:

par | \- структура параметров ассоциативного вида [AssociationViewParam](structassociationviewparam.html),  
---|---  
bitVector | \- набор [типов стандартных видов](standartviewtypes.html), которые нужно создать,  
dx | \- расстояние между видами по горизонтали,  
dy | \- расстояние между видами по вертикали.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Последний из созданных видов становится текущим.

2\. При использовании Unicode следует использовать функцию [ksCreateSheetStandartViewsW](kscreatesheetstandartviewsw.html).

Подразделы:

(отсутствуют)
