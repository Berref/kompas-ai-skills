# Clear - Очистить группу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Группы ](bb2344629.html) > [Интерфейс IDrawingGroup ](idrawinggroup.html) > [IDrawingGroup - методы ](idrawinggroup_methods.html) |  Scroll [ [ [ ](idrawinggroup_close.html "К следующему разделу")](idrawinggroup_methods.html "На уровень выше")](idrawinggroup_addregion.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawinggroup.html)

Синтаксис Automation:

BOOL Clear( BOOL DeleteTmp );

Синтаксис COM:

HRESULT Clear( BOOL DeleteTmp,

BOOL * Result );

Входные параметры:

DeleteTmp | \- удалять ли временные объекты.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет удалить все объекты из группы.

Подразделы:

(отсутствуют)
