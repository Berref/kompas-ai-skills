# GetHyperLinkParam - Получить параметры гиперссылки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Ограничения ](bb2391397.html) > [Интерфейс IDrawingObject1 ](idrawingobject1.html) > [IDrawingObject1 - методы ](idrawingobject1_methods.html) |  Scroll [ [ [ ](idrawingobject1_newconstraint.html "К следующему разделу")](idrawingobject1_methods.html "На уровень выше")](idrawingobject1_getcurve2d.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingobject1.html)

Синтаксис Automation:

BSTR GetHyperLinkParam( ksHyperLinkTypeEnum * Type,

IDrawingObject ** LinkObject,

long * Level );

Синтаксис COM:

HRESULT GetHyperLinkParam( ksHyperLinkTypeEnum * Type,

IDrawingObject ** LinkObject,

long * Level,

BSTR * Result );

Возвращаемое значение:

текст гиперссылки.  
---  
  
Возвращаемое значение:

Type | \- тип ссылки,  
---|---  
LinkObject | \- объект, на который сделана ссылка,  
Level | \- уровень.  
  
Подразделы:

(отсутствуют)
