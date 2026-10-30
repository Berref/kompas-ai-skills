# FindObject - Найти объект в текущем документе по объекту из другого документа

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_findobjectsbypoint.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_getsummmatrix.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

LPDISPATCH FindObject( LPDISPATCH Obj, LPDISPATCH SourcePart );

Синтаксис COM:

HRESULT FindObject( IModelObject * Obj, IPart7 * SourcePart, IModelObject ** Result );

Входные параметры:

Obj | \- указатель на объект,  
---|---  
SourcePart | \- владелец объекта.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
