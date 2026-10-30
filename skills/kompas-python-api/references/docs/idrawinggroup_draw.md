# Draw - Отрисовать в окне

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Группы ](bb2344629.html) > [Интерфейс IDrawingGroup ](idrawinggroup.html) > [IDrawingGroup - методы ](idrawinggroup_methods.html) |  Scroll [ [ [ ](idrawinggroup_existobject.html "К следующему разделу")](idrawinggroup_methods.html "На уровень выше")](idrawinggroup_detachobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawinggroup.html)

Синтаксис Automation:

BOOL Draw( OLE_HANDLE HWnd );

Синтаксис COM:

HRESULT Draw( OLE_HANDLE HWnd,

BOOL * Result );

Входные параметры:

HWnd | \- дескриптор окна.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет отрисовать группу в окне.

Подразделы:

(отсутствуют)
