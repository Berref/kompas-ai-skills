# AddStandartViews - Создать группу стандартных ассоциативных видов (добавить виды в коллекцию)

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObjects ](idrawingobjects.html) > [IDrawingObjects - свойства ](idrawingobjects_props.html) > [Интерфейс IViews ](iviews.html) > [IViews - методы ](iviews_methods.html) |  Scroll [ [ [ ](idrawingobject.html "К следующему разделу")](iviews_methods.html "На уровень выше")](iviews_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iviews.html)

Синтаксис Automation:

BOOL AddStandartViews (BSTR FileName,

BSTR ProjectionName,

VARIANT ProjectionsTypes,

double X,

double Y,

double Scale,

double DX,

double DY );

Синтаксис COM:

HRESULT AddStandartViews (BSTR FileName,

BSTR ProjectionName,

VARIANT ProjectionsTypes,

double X,

double Y,

double Scale,

double DX,

double DY,

BOOL * Result);

Входные параметры:

FileName | \- имя файла модели-источника для проекции,  
---|---  
ProjectionName | \- ориентация модели,  
ProjectionsTypes | \- массив SAFEARRAY VT | VT_I4 типов проекций,  
X, Y | \- точка привязки группы видов,  
Scale | \- масштаб,  
DX, DY | \- расстояние между видами.  
  
Возвращаемое значение:

TRUE | \- в случае удачи.  
---|---  
  
Подразделы:

(отсутствуют)
