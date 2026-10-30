# GetObjectById - Получить объект по его уникальному идентификатору

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_getobjectsgabarit.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_gethyperlinkobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

LPDISPATCH GetObjectById( int64 Id );

Синтаксис COM:

HRESULT GetObjectById( int64 Id, IDrawingObject ** Result );

Возвращаемое значение:

| \- указатель на интерфейс объекта [IDrawingObject](idrawingobject.html).  
---|---  
  
Входные параметры:

Id | \- идентификатор объекта.  
---|---  
  
Подразделы:

(отсутствуют)
