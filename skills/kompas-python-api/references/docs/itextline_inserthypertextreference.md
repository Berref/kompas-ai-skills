# InsertHypertextReference - Добавить ссылку в текст

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс ITextLine ](itextline.html) > [ITextLine - методы ](itextline_methods.html) |  Scroll [ [ [ ](itextline_replacestr.html "К следующему разделу")](itextline_methods.html "На уровень выше")](itextline_find.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextline.html)

Синтаксис Automation:

LPDISPATCH InsertHypertextReference( long TextItemIndex,

IKompasAPIObject * Object,

ksHypertextTypeEnum Type,

BOOL Brackets,

long TextLineIndex,

long Precision,

double PropertyId);

Синтаксис COM:

HRESULT InsertHypertextReference( long TextItemIndex,

IKompasAPIObject * Object,

ksHypertextTypeEnum Type,

BOOL Brackets,

long TextLineIndex,

long Precision,

double PropertyId,

ITextItem ** Result );

Входные параметры:

TextItemIndex | \- индекс компонента текста,  
---|---  
Object | \- объект, на который сделана ссылка,  
Type | \- тип ссылки,  
Brackets | \- признак скобок,  
TextLineIndex | \- индекс строки в тексте,  
Precision | \- точность вывода числовых значений,  
PropertyId | \- идентификатор свойства.  
  
Возвращаемое значение:

\- указатель на интерфейс компонента текста, содержащего ссылку.  
---  
  
Подразделы:

(отсутствуют)
