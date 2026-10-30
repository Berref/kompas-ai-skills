# WriteFragment - Записать в фрагмент

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Группы ](bb2344629.html) > [Интерфейс IDrawingGroup ](idrawinggroup.html) > [IDrawingGroup - методы ](idrawinggroup_methods.html) |  Scroll [ [ [ ](idrawinggroup_writetoclip.html "К следующему разделу")](idrawinggroup_methods.html "На уровень выше")](idrawinggroup_store.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawinggroup.html)

Синтаксис Automation:

BOOL WriteFragment( BSTR FileName,

BSTR Comment,

double XBase,

double YBase );

Синтаксис COM:

HRESULT WriteFragment( BSTR FileName,

BSTR Comment,

double XBase,

double YBase,

BOOL * Result );

Входные параметры:

FileName | \- имя файла фрагмента,  
---|---  
Comment | \- комментарий,  
XBase, YBase | \- координаты базовой точки в СК вида,  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет записать группу в фрагмент.

Подразделы:

(отсутствуют)
