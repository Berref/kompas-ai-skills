# InsertHypertextReference - Добавить ссылку в свойство

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IPropertyKeeper ](ipropertykeeper.html) > [IPropertyKeeper - методы ](ipropertykeeper_methods.html) |  Scroll [ [ [ ](ipropertykeeper_setpropertyvalue.html "К следующему разделу")](ipropertykeeper_methods.html "На уровень выше")](ipropertykeeper_getuserdatastoragesmanager.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertykeeper.html)

Синтаксис Automation:

BOOL InsertHypertextReference( IProperty * Property,

IKompasAPIObject * Object,

ksHypertextTypeEnum Type,

BOOL Brackets,

long TextLineIndex,

long Precision,

double PropertyId;

Синтаксис COM:

HRESULT InsertHypertextReference( IProperty * Property,

IKompasAPIObject * Object,

ksHypertextTypeEnum Type,

BOOL Brackets,

long TextLineIndex,

long Precision,

double PropertyId,

BOOL * Result );

Входные параметры:

Property | \- свойство, в которое добавляется ссылка,  
---|---  
Object | \- объект, на свойство или текст которого ссылаемся,  
Type | \- тип ссылки,  
Brackets | \- добавлять скобки,  
TextLineIndex | \- индекс строки в тексте объекта,  
Precision | \- количество знаков после запятой,  
PropertyId | \- идентификатор свойства, на которое ссылаемся.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
