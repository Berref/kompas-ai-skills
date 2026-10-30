# GetGabarit - Габарит объектов группы

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Группы ](bb2344629.html) > [Интерфейс IDrawingGroup ](idrawinggroup.html) > [IDrawingGroup - методы ](idrawinggroup_methods.html) |  Scroll [ [ [ ](idrawinggroup_open.html "К следующему разделу")](idrawinggroup_methods.html "На уровень выше")](idrawinggroup_existobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawinggroup.html)

Синтаксис Automation:

BOOL GetGabarit( double * X1, double * Y1, double * X2, double * Y2 );

Синтаксис COM:

HRESULT GetGabarit( double * X1, double * Y1, double * X2, double * Y2, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

X1, Y1 | \- первая точка габарита - левая нижняя,  
---|---  
X2, Y2 | \- вторая точка габарита - правая верхняя.  
  
Версия Компас v23

Подразделы:

(отсутствуют)
