# Update - Обновить данные объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) |  Scroll [ [ [ ](ilayer.html "К следующему разделу")](idrawingobject_methods.html "На уровень выше")](idrawingobject_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingobject.html)

Синтаксис Automation:

BOOL Update();

Синтаксис COM:

HRESULT Update ([out, retval] VARIANT_BOOL* pRes);

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Метод Update необходимо вызвать для объекта, свойства которого были изменены (после вызова Set- cвойств или методов интерфейса), чтобы эти изменения вступили в силу.

2\. Метод Update вернёт TRUE в случае успеха и FALSE в случае неудачи.

3\. Вызов Update сработает как при изменении одного свойства, так и при изменении группы свойств объекта.

Подразделы:

(отсутствуют)
