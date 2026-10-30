# ksCreateDocument - Создать текстовый документ

[API интерфейсов. Версия 5](ag57940.html) > [Текстовый документ (Интерфейс ksDocumentTxt) ](ksdocumenttxt.html) > [ksDocumentTxt - методы ](ksdocumenttxt_methods.html) |  Scroll [ [ [ ](ksdocumenttxt_ksgetdocumentpagescount.html "К следующему разделу")](ksdocumenttxt_methods.html "На уровень выше")](ksdocumenttxt_ksclosedocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumenttxt.html)

Аналог данного метода при использовании API экспортных функций - [CreateTextDocument](createtextdocument.html).

Синтаксис Automation:

BOOL ksCreateDocument (LPDISPATCH par);

Входные параметры:

par | \- указатель на интерфейс параметров текстового документа [ksTextDocumentParam](kstextdocumentparam.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Созданный документ становится текущим.

Подразделы:

(отсутствуют)
