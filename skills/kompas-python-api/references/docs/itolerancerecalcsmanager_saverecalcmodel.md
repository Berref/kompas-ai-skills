# SaveRecalcModel - Сохранить пересчитанную копию модели

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Пересчет модели с учетом допусков ](bc2277893.html) > [Интерфейс IToleranceRecalcsManager ](itolerancerecalcsmanager.html) > [IToleranceRecalcsManager - методы ](itolerancerecalcsmanager_methods.html) |  Scroll [ [ [ ](itolerancerecalc.html "К следующему разделу")](itolerancerecalcsmanager_methods.html "На уровень выше")](itolerancerecalcsmanager_getrecalc.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itolerancerecalcsmanager.html)

Синтаксис Automation:

BOOL SaveRecalcModel( BSTR FileName );

Синтаксис СОМ:

HRESULT SaveRecalcModel( BSTR FileName, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры

FileName | \- имя файла, в который будет сохранена модель.  
---|---  
  
Подразделы:

(отсутствуют)
