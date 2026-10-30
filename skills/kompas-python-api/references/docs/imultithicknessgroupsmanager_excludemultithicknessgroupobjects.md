# ExcludeMultiThicknessGroupObjects - Исключить объекты из групп

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IMultiThicknessGroupsManager ](imultithicknessgroupsmanager.html) > [MultiThicknessGroupsManager - методы ](imultithicknessgroupsmanager_methods.html) |  Scroll [ [ [ ](imultithicknessgroupsmanager_clearmultithicknessgroups.html "К следующему разделу")](imultithicknessgroupsmanager_methods.html "На уровень выше")](imultithicknessgroupsmanager_destroymultithicknessgroup.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultithicknessgroupsmanager.html)

Синтаксис Automation:

BOOL ExcludeMultiThicknessGroupObjects( VARIANT Objects );

Синтаксис COM:

HRESULT ExcludeMultiThicknessGroupObjects( VARIANT Objects, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
  
Входные параметры:

Objects | \- Грань VT_DISPATCH или список граней массив SafeArray VT_ARRAY | VT_DISPATCH.  
---|---  
  
Подразделы:

(отсутствуют)
