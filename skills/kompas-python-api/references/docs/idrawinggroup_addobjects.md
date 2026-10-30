# AddObjects - Добавить объекты в группу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Группы ](bb2344629.html) > [Интерфейс IDrawingGroup ](idrawinggroup.html) > [IDrawingGroup - методы ](idrawinggroup_methods.html) |  Scroll [ [ [ ](idrawinggroup_addregion.html "К следующему разделу")](idrawinggroup_methods.html "На уровень выше")](idrawinggroup_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawinggroup.html)

Синтаксис Automation:

BOOL AddObjects( VARIANT Objects );

Синтаксис COM:

HRESULT AddObjects( VARIANT Objects,

BOOL * Result );

Входные параметры:

Objects | \- объект или массив объектов для добавления в группу ( VARIANT типа VT_DISPATCH или VT_ARRAY | VT_DISPATCH).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет добавить объекты в группу.

Подразделы:

(отсутствуют)
