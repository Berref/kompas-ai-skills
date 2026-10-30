# DeleteMultiThicknessGroup - Удалить группу объектов с заданной толщиной

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IMultiThicknessGroupsManager ](imultithicknessgroupsmanager.html) > [MultiThicknessGroupsManager - методы ](imultithicknessgroupsmanager_methods.html) |  Scroll [ [ [ ](imultithicknessgroupsmanager_destroymultithicknessgroup.html "К следующему разделу")](imultithicknessgroupsmanager_methods.html "На уровень выше")](imultithicknessgroupsmanager_addmultithicknessgroup.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultithicknessgroupsmanager.html)

Синтаксис Automation :

BOOL DeleteMultiThicknessGroup( ksMultiThicknessGroupTypeEnum Type, long Index );

Синтаксис COM :

HRESULT DeleteMultiThicknessGroup( ksMultiThicknessGroupTypeEnum Type, long Index, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
  
Входные параметры:

Type | \- Тип группы параметров из перечисления [ksMultiThicknessGroupTypeEnum](ksmultithicknessgrouptypeenum.html),  
---|---  
Index | \- Индекс параметров в группе.  
  
Подразделы:

(отсутствуют)
