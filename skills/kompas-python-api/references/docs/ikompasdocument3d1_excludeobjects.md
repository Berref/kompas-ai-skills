# ExcludeObjects - Исключить из расчета объект или объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument3D1 ](ikompasdocument3d1.html) > [IKompasDocument3D1 - методы ](ikompasdocument3d1_methods.html) |  Scroll [ [ [ ](ikompasdocument3d1_executeprocessofinsertcomponentfromfile.html "К следующему разделу")](ikompasdocument3d1_methods.html "На уровень выше")](ikompasdocument3d1_converttoadditionformat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d1.html)

Синтаксис Automation:

BOOL ExcludeObjects( VARIANT Objects, BOOL Excl );

Синтаксис COM:

HRESULT ExcludeObjects( VARIANT Objects, BOOL Excl, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- объект (VT_DISPATCH) или Список объектов VT_ARRAY | VT_DISPATCH,  
---|---  
Excl | \- TRUE - исключить из расчета \- FALSE - включить в расчет.  
  
Подразделы:

(отсутствуют)
