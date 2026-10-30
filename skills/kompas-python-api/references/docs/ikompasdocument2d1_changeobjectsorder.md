# ChangeObjectsOrder - Изменить порядок отрисовки объектов документа

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_clearregion.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_addvariable.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL ChangeObjectsOrder( VARIANT Objects, IDrawingObject * OrderObject, ksChangeOrderType OrderType );

Синтаксис COM:

HRESULT ChangeObjectsOrder( VARIANT Objects, IDrawingObject * OrderObject, ksChangeOrderType OrderType, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- список объектов в виде SAFEARRAY'я DISPATCH - VT_ARRAY | VT_DISPATCH,  
---|---  
OrderObject | \- объект, относительно которого изменяется отрисовка объектов Objects [IDrawingObject](idrawingobject.html),  
OrderType | \- тип изменения порядка объектов [ksChangeOrderType](kschangeordertype.html).  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
