# InitByMatrix3D - Установить систему координат по матрице SAFEARRAY double (VT_ARRAY | VT_R8)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) > [Интерфейс IConjunctivePoint ](iconjunctivepoint.html) > [IConjunctivePoint - методы ](iconjunctivepoint_methods.html) |  Scroll [ [ [ ](iconjunctivepoint_setdirectionobject1.html "К следующему разделу")](iconjunctivepoint_methods.html "На уровень выше")](iconjunctivepoint_getvector.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconjunctivepoint.html)

Синтаксис Automation:

BOOL InitByMatrix3D( VARIANT mtr );

Синтаксис COM:

HRESULT InitByMatrix3D( VARIANT mtr, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

mtr | \- массив координат SAFEARRAY double (VT_ARRAY | VT_R8).  
---|---  
  
Подразделы:

(отсутствуют)
