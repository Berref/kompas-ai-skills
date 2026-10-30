# AddRecalcCopy - Создать пересчет размеров по образцу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Пересчет модели с учетом допусков ](bc2277893.html) > [Интерфейс IToleranceRecalcsManager ](itolerancerecalcsmanager.html) > [IToleranceRecalcsManager - методы ](itolerancerecalcsmanager_methods.html) |  Scroll [ [ [ ](itolerancerecalcsmanager_getrecalc.html "К следующему разделу")](itolerancerecalcsmanager_methods.html "На уровень выше")](itolerancerecalcsmanager_addrecalc.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itolerancerecalcsmanager.html)

Синтаксис Automation:

LPDISPATCH AddRecalcCopy( IToleranceRecalc * Source );

Синтаксис СОМ:

HRESULT AddRecalcCopy( IToleranceRecalc * Source, IToleranceRecalc ** Result );

Возвращаемое значение:

  
| \- указатель на интерфейс пересчета размеров [IToleranceRecalc](itolerancerecalc.html).  
---|---  
  
Входные параметры

Source | \- указатель на копируемый пересчет размеров [IToleranceRecalc](itolerancerecalc.html).  
---|---  
  
Подразделы:

(отсутствуют)
