# ReadFragment - Добавить объекты в группу из фрагмента

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Группы ](bb2344629.html) > [Интерфейс IDrawingGroup ](idrawinggroup.html) > [IDrawingGroup - методы ](idrawinggroup_methods.html) |  Scroll [ [ [ ](idrawinggroup_readfromclip.html "К следующему разделу")](idrawinggroup_methods.html "На уровень выше")](idrawinggroup_open.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawinggroup.html)

Синтаксис Automation:

BOOL ReadFragment( BSTR FileName,

BOOL CurentLayer,

double XBase,

double YBase,

double Scale,

double Angle,

BOOL ScaleProjLinesSize );

Синтаксис COM:

HRESULT ReadFragment( BSTR FileName,

BOOL CurentLayer,

double XBase,

double YBase,

double Scale,

double Angle,

BOOL ScaleProjLinesSize,

BOOL * Result );

Входные параметры:

FileName | \- имя файла фрагмента,  
---|---  
CurentLayer | \- тип размещения по слоям FALSE - на свои слои, TRUE - в текущий слой,  
XBase, YBase | \- координаты базовой точки в СК вида,  
Scale | \- масштаб,  
Angle | \- угол поворота в СК вида,  
ScaleProjLinesSize | \- масштабировать ли проекционные линии.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет добавить объекты в группу из фрагмента.

Подразделы:

(отсутствуют)
