# DeletePoint - Удалить точку

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс INurbs ](inurbs.html) > [INurbs - методы ](inurbs_methods.html) |  Scroll [ [ [ ](inurbs_getnurbsparams.html "К следующему разделу")](inurbs_methods.html "На уровень выше")](inurbs_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inurbs.html)

Синтаксис Automation:

BOOL DeletePoint( long Index );

Синтаксис COM:

HRESULT DeletePoint( long Index,

BOOL * Result );

Входные параметры:

Index | \- индекс удаляемой точки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет удалить заданную точку NURBS-кривой.

Подразделы:

(отсутствуют)
