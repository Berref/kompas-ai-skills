# Add - Добавить новый подраздел

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationSubsections ](ispecificationsubsections.html) > [ISpecificationSubsections - методы ](ispecificationsubsections_methods.html) |  Scroll [ [ [ ](ispecificationtuningsections.html "К следующему разделу")](ispecificationsubsections_methods.html "На уровень выше")](ispecificationsubsections_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationsubsections.html)

Синтаксис Automation:

LPDISPATCH Add (BSTR Name, short Number);

Синтаксис COM:

HRESULT Add ([in] BSTR Name,

[in] short Number,

[out, retval] ISpecificationSubsections** Result);

Входные параметры:

Name | \- имя подраздела,  
---|---  
Number | \- номер подраздела.  
  
Возвращаемое значение:

| \- Указатель на интерфейс подраздела спецификации [ISpecificationSubsection](ispecificationsubsection.html).  
---|---  
  
Подразделы:

(отсутствуют)
