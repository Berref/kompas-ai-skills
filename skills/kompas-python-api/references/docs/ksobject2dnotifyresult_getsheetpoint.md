# GetSheetPoint - Получить координаты точки в системе координат листа

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksObject2DNotifyResultIObject2DNotifyResult ](ksobject2dnotifyresult.html) > [ksObject2DNotifyResult - методы ](ksobject2dnotifyresult_methods.html) |  Scroll [ [ [ ](ksobject2dnotifyresult_iscopy.html "К следующему разделу")](ksobject2dnotifyresult_methods.html "На уровень выше")](ksobject2dnotifyresult_getscale.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobject2dnotifyresult.html)

Синтаксис Automation:

BOOL GetSheetPoint (BOOL from, double *x, double *y);

Синтаксис COM:

BOOL GetSheetPoint (BOOL from, double *x, double *y);

Входные параметры:

from | \- TRUE - начало сдвига, центр поворота, центр масштабирования, первая точка оси симметрии, начало копирования, \- FALSE - конец сдвига, вторая точка оси симметрии, конец копирования.  
---|---  
  
Выходные параметры:

x, y, | \- значения координат точки в системе координат листа.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
