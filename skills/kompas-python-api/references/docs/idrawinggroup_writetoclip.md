# WriteToClip - Записать объекты в клип

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Группы ](bb2344629.html) > [Интерфейс IDrawingGroup ](idrawinggroup.html) > [IDrawingGroup - методы ](idrawinggroup_methods.html) |  Scroll [ [ [ ](idrawinggroups.html "К следующему разделу")](idrawinggroup_methods.html "На уровень выше")](idrawinggroup_writefragment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawinggroup.html)

Синтаксис Automation:

BOOL WriteToClip( BOOL AttrCopy,

BOOL SpcObjCopy );

Синтаксис COM:

HRESULT WriteToClip( BOOL AttrCopy,

BOOL SpcObjCopy,

BOOL * Result );

Входные параметры:

AttrCopy | \- копировать ли атрибуты,  
---|---  
SpcObjCopy | \- копировать ли объекты спецификации.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет скопировать объекты из группы в клип.

Подразделы:

(отсутствуют)
