# GetPoint - Получить координаты точки дуги 3D

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IArc3D ](iarc3d.html) > [IArc3D - методы ](iarc3d_methods.html) |  Scroll [ [ [ ](iarc3d_setpoint.html "К следующему разделу")](iarc3d_methods.html "На уровень выше")](iarc3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iarc3d.html)

Синтаксис Automation:

BOOL GetPoint( ksArc3DParameterEnum Index, double * X, double * Y, double * Z );

Синтаксис COM:

HRESULT GetPoint( ksArc3DParameterEnum Index, double * X, double * Y, double * Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Index - индекс вершины из перечисления [ksArc3DParameterEnum](ksarc3dparameterenum.html).

Выходные параметры

X, Y, Z - координаты точки.

Подразделы:

(отсутствуют)
