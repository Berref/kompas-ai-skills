# ksGetDocumentByReference - Получить интерфейс документа по указателю на документ

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksgetdocumenttype.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksgetdocoptions.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Синтаксис Automation:

LPDISPATCH ksGetDocumentByReference (long docRef);

Входной параметр:

docRef | \- указатель на документ.  
---|---  
  
Возвращаемое значение:

Указатель на интерфейс документа |   
---|---  
  
Примечание:

Если docRef = 0, возвращается указатель на интерфейс IDispatch активного документа.

Подразделы:

(отсутствуют)
