# Delete - Удалить объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) |  Scroll [ [ [ ](idrawingobject_update.html "К следующему разделу")](idrawingobject_methods.html "На уровень выше")](idrawingobject_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingobject.html)

Синтаксис Automation:

BOOL Delete();

Синтаксис COM:

HRESULT Delete ([out, retval] VARIANT_BOOL* pRes);

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

После успешного выполнения метода объект будет удален из модели. Свойство Valid для объекта будет возвращать FALSE. Все методы интерфейса возвращают ошибку (FALSE).

Подразделы:

(отсутствуют)
