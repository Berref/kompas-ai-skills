# Update - Обновить данные объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [3D-объект ](bc2229904.html) > [Интерфейс IModelObject ](imodelobject.html) > [IModelObject - методы ](imodelobject_methods.html) |  Scroll [ [ [ ](imeshobject3d.html "К следующему разделу")](imodelobject_methods.html "На уровень выше")](imodelobject_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imodelobject.html)

Синтаксис Automation:

BOOL Update( );

Синтаксис COM:

HRESULT Update ( [out, retval] VARIANT_BOOL* pRes );

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
