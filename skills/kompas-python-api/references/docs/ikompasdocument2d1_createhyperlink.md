# CreateHyperLink - Создать гиперссылку

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_creatematrix.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_copyobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL CreateHyperLink( VARIANT Objects,

ksHyperLinkTypeEnum Type,

BSTR Text,

IDrawingObject * LinkObject,

longLevel );

Синтаксис COM:

HRESULT CreateHyperLink( VARIANT Objects,

ksHyperLinkTypeEnum Type,

BSTR Text,

IDrawingObject * LinkObject,

long Level,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- VT_DISPATCH или массив VT_ARRAY | VT_DISPATCH объектов, содержащих ссылку,  
---|---  
Type | \- тип ссылки,  
Text | \- текст ссылки,  
LinkObject | \- объект, на который сделана ссылка,  
Level | \- уровень.  
  
Подразделы:

(отсутствуют)
