# GetHyperLinkObjects - Получить объекты, имеющие гиперссылку

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_getobjectbyid.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_executeprocessofdocumentfromfile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

VARIANT GetHyperLinkObjects( ksHyperLinkTypeEnum Type,

IDrawingObject * LinkObject,

long Level,

BSTR Text );

Синтаксис COM:

HRESULT GetHyperLinkObjects( ksHyperLinkTypeEnum Type,

IDrawingObject * LinkObject,

long Level,

BSTR Text,

VARIANT * Result );

Возвращаемое значение:

VT_DISPATCH или массив VT_ARRAY | VT_DISPATCH объектов, содержащих ссылку

Входные параметры:

Type | \- тип ссылки,  
---|---  
Text | \- текст ссылки,  
LinkObject | \- объект, на который сделана ссылка,  
Level | \- уровень.  
  
Подразделы:

(отсутствуют)
