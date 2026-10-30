# DestroyObjects - Разрушить объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_executeprocessofdocumentfromfile.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_deletematrix.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL DestroyObjects( VARIANT Objects );

Синтаксис COM:

HRESULT DestroyObjects( VARIANT Objects, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- cписок объектов в виде SAFEARRAY'я DISPATCH - VT_ARRAY | VT_DISPATCH.  
---|---  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
