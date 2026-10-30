# GetObjectId - Получить строковый идентификатор объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument1 ](ikompasdocument1.html) > [IKompasDocument1 - методы ](ikompasdocument1_methods.html) |  Scroll [ [ [ ](ikompasdocument1_redrawdocument.html "К следующему разделу")](ikompasdocument1_methods.html "На уровень выше")](ikompasdocument1_getinterface.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument1.html)

Синтаксис Automation:

BSTR GetObjectId( IKompasAPIObject * Object, IKompasAPIObject * Parent );

Синтаксис COM:

HRESULT GetObjectId( IKompasAPIObject * Object, IKompasAPIObject * Parent, BSTR * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Object | \- Указатель на интерфейс объекта [IKompasAPIObject](ikompasapiobject.html),  
---|---  
Parent | \- Владелец объекта, относительно которого нужно сформировать идентификатор. В текущей реализации не используется. Зарезервировано на будущее.  
  
Версия Компас v21

Подразделы:

(отсутствуют)
