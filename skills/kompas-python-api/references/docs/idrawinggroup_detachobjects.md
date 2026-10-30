# DetachObjects - Исключить объекты из группы

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Группы ](bb2344629.html) > [Интерфейс IDrawingGroup ](idrawinggroup.html) > [IDrawingGroup - методы ](idrawinggroup_methods.html) |  Scroll [ [ [ ](idrawinggroup_draw.html "К следующему разделу")](idrawinggroup_methods.html "На уровень выше")](idrawinggroup_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawinggroup.html)

Синтаксис Automation:

BOOL DetachObjects( VARIANT Objects,

BOOL DeleteTmp );

Синтаксис COM:

HRESULT DetachObjects( VARIANT Objects,

BOOL DeleteTmp,

BOOL * Result );

Входные параметры:

Objects | \- объект или массив объектов для удаления из группы( VARIANT типа VT_DISPATCH или VT_ARRAY | VT_DISPATCH ),  
---|---  
DeleteTmp | \- удалять ли временные объекты.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет исключить объекты из группы.

Подразделы:

(отсутствуют)
