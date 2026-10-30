# AddRegion - Добавить объекты в группу рамкой

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Группы ](bb2344629.html) > [Интерфейс IDrawingGroup ](idrawinggroup.html) > [IDrawingGroup - методы ](idrawinggroup_methods.html) |  Scroll [ [ [ ](idrawinggroup_clear.html "К следующему разделу")](idrawinggroup_methods.html "На уровень выше")](idrawinggroup_addobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawinggroup.html)

Синтаксис Automation:

BOOL AddRegion( long RegionType,

double XMin,

double YMin,

double XMax,

double YMax );

Синтаксис COM:

HRESULT AddRegion( ksRegionTypeEnum RegionType,

double XMin,

double YMin,

double XMax,

double YMax,

BOOL * Result );

Входные параметры:

RegionType | \- тип рамки из перечисления [ksRegionTypeEnum](ksregiontypeenum.html),  
---|---  
XMin, YMin | \- координаты нижнего левого угла рамки,  
XMax, YMax | \- координаты верхнего правого угла рамки.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет добавить объекты в группу рамкой.

Подразделы:

(отсутствуют)
