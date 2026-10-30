# ExistObject - Проверить, есть ли объект в группе

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Группы ](bb2344629.html) > [Интерфейс IDrawingGroup ](idrawinggroup.html) > [IDrawingGroup - методы ](idrawinggroup_methods.html) |  Scroll [ [ [ ](idrawinggroup_getgabarit.html "К следующему разделу")](idrawinggroup_methods.html "На уровень выше")](idrawinggroup_draw.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawinggroup.html)

Синтаксис Automation:

BOOL ExistObject( LPDISPATCH Object );

Синтаксис COM:

HRESULT ExistObject( IDrawingObject * Object,

BOOL * Result );

Входные параметры:

Object | \- объект, наличие которого в группе надо проверить.  
---|---  
  
Возвращаемое значение:

TRUE | \- объект есть в группе,  
---|---  
FALSE | \- объекта нет в группе.  
  
Примечание:

Метод позволяет определить, есть ли в группе заданный объект.

Подразделы:

(отсутствуют)
