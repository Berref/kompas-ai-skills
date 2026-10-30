# ksGetDocumentType - Получить тип документа

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksgetdocumenttypebynameex.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksgetdocumentbyreference.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Аналог данного метода при использовании API экспортных функций - [ksGetDocumentType](ksgetdocumenttype.html).

Синтаксис Automation:

long ksGetDocumentType (long doc);

Входной параметр:

doc | \- указатель на документ.  
---|---  
  
Возвращаемое значение:

тип документа [DocType](doctype.html) | \- при успешном завершении,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если указатель doc = 0, возвращается тип активного документа.

Подразделы:

(отсутствуют)
