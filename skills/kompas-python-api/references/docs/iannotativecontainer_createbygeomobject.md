# CreateByGeomObject - Преобразовать геометрический объект в аннотационный

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Макрообъекты ](bb2346750.html) > [Интерфейс IAnnotativeContainer ](iannotativecontainer.html) > [IAnnotativeContainer - методы ](iannotativecontainer_methods.html) |  Scroll [ [ [ ](iannotativeobject.html "К следующему разделу")](iannotativecontainer_methods.html "На уровень выше")](iannotativecontainer_addobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iannotativecontainer.html)

Синтаксис Automation:

LPDISPATCH CreateByGeomObject( LPDISPATCH obj );

Синтаксис COM:

HRESULT CreateByGeomObject( IDrawingObject * obj,

IAnnotativeObject ** Result );

Входные параметры:

obj | \- указатель на интерфейс геометрического объекта [IDrawingObject](idrawingobject.html).  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс аннотационного объекта [IAnnotativeObject](iannotativeobject.html).  
---|---  
  
Примечание:

Метод позволяет преобразовать геометрический объект в аннотационный и добавить его в контейнер.

Подразделы:

(отсутствуют)
