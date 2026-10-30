# Change - Изменить параметры подраздела

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationSubsection ](ispecificationsubsection.html) > [ISpecificationSubsection - методы ](ispecificationsubsection_methods.html) |  Scroll [ [ [ ](ispecificationsubsection_delete.html "К следующему разделу")](ispecificationsubsection_methods.html "На уровень выше")](ispecificationsubsection_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationsubsection.html)

Синтаксис Automation:

BOOL Change (BSTR Name, short Number);

Синтаксис COM:

HRESULT Change ([in] BSTR Name,

[in] short Number,

[out, retval] VARIANT_BOOL* pVal);

Входные параметры:

Name | \- новое имя подраздела,  
---|---  
Number | \- новый номер подраздела.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
