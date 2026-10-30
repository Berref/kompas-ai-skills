# SetObjects - Задать объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IUserDesignationCompObj ](iuserdesignationcompobj.html) > [IUserDesignationCompObj - методы ](iuserdesignationcompobj_methods.html) |  Scroll [ [ [ ](bc2277893.html "К следующему разделу")](iuserdesignationcompobj_methods.html "На уровень выше")](iuserdesignationcompobj_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserdesignationcompobj.html)

Синтаксис Automation:

BOOL SetObjects( VARIANT Objects );

Синтаксис COM:

HRESULT SetObjects( VARIANT Objects, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- массив SafeArray (VT_ARRAY | VT_DISPATCH) объектов.  
---|---  
  
Подразделы:

(отсутствуют)
