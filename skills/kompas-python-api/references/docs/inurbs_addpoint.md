# AddPoint - Добавить точку

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс INurbs ](inurbs.html) > [INurbs - методы ](inurbs_methods.html) |  Scroll [ [ [ ](inurbs_clear.html "К следующему разделу")](inurbs_methods.html "На уровень выше")](inurbs_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inurbs.html)

Синтаксис Automation:

BOOL AddPoint( long Index,

double X,

double Y

double Weight );

Синтаксис COM:

HRESULT AddPoint( long Index,

double X,

double Y,

double Weight,

BOOL * Result );

Входные параметры:

Index | \- индекс добавляемой точки,  
---|---  
X, Y | \- координаты добавляемой точки,  
Weight | \- вес точки.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет добавить точку в NURBS-кривую.

Подразделы:

(отсутствуют)
