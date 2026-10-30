# GetGabarit - Габарит

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Технические требования ](bc2278438.html) > [Интерфейс ITechnicalDemand3D ](itechnicaldemand3d.html) > [ITechnicalDemand3D - методы ](itechnicaldemand3d_methods.html) |  Scroll [ [ [ ](itechnicaldemand3d_iscreated.html "К следующему разделу")](itechnicaldemand3d_methods.html "На уровень выше")](itechnicaldemand3d_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itechnicaldemand3d.html)

Синтаксис Automation:

BOOL GetGabarit( long * Left, long * Top, long * Right, long * Bottom );

Синтаксис COM :

HRESULT GetGabarit( long * Left, long * Top, long * Right, long * Bottom, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

Left, Top, Right, Bottom | \- габариты технических требований в экранных координатах.  
---|---  
  
Версия Компас v21

Подразделы:

(отсутствуют)
