# AddObjects - Добавить объекты в группу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Макрообъекты ](bb2346750.html) > [Интерфейс IAnnotativeContainer ](iannotativecontainer.html) > [IAnnotativeContainer - методы ](iannotativecontainer_methods.html) |  Scroll [ [ [ ](iannotativecontainer_createbygeomobject.html "К следующему разделу")](iannotativecontainer_methods.html "На уровень выше")](iannotativecontainer_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iannotativecontainer.html)

Синтаксис Automation:

BOOL AddObjects( VARIANT Objects );

Синтаксис COM:

HRESULT AddObjects( VARIANT Objects,

BOOL * Result );

Входные параметры:

Objects | \- объект или массив объектов для добавления в группу ( VARIANT типа VT_DISPATCH или VT_ARRAY | VT_DISPATCH ).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет добавить объекты в группу.

Подразделы:

(отсутствуют)
