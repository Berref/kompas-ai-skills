# FindObjectById - Найти объект по строковому идентификатору

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument1 ](ikompasdocument1.html) > [IKompasDocument1 - методы ](ikompasdocument1_methods.html) |  Scroll [ [ [ ](i_getactivetoolbarset.html "К следующему разделу")](ikompasdocument1_methods.html "На уровень выше")](ikompasdocument1_draw.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument1.html)

Синтаксис Automation:

LPDISPATCH FindObjectById( BSTR Id, IKompasAPIObject * Parent );

Синтаксис COM:

HRESULT FindObjectById( BSTR Id, IKompasAPIObject * Parent, IKompasAPIObject * * Result );

Возвращаемое значение:

| Указатель на интерфейс объекта [IKompasAPIObject](ikompasapiobject.html).  
---|---  
  
Входные параметры:

Id | \- идентификатор объекта, полученный из функции [IKompasDocument1::GetObjectId](ikompasdocument1_getobjectid.html),  
---|---  
Parent | \- Владелец объекта, относительно которого нужно сформировать идентификатор. В текущей реализации не используется. Зарезервировано на будущее.  
  
Версия Компас v21

Подразделы:

(отсутствуют)
