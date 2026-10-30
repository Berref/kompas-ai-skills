# ksSaveDocumentEx - Сохранить документ в выбранной версии

[API интерфейсов. Версия 5](ag57940.html) > [Текстовый документ (Интерфейс ksDocumentTxt) ](ksdocumenttxt.html) > [ksDocumentTxt - методы ](ksdocumenttxt_methods.html) |  Scroll [ [ [ ](ksdocumenttxt_kssetobjparam.html "К следующему разделу")](ksdocumenttxt_methods.html "На уровень выше")](ksdocumenttxt_kssavedocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumenttxt.html)

Аналог данного метода при использовании API экспортных функций - [SaveDocumentEx](savedocumentex.html).

Синтаксис Automation:

BOOL ksSaveDocumentEx (BSTR fileName, long saveMode);

Входные параметры:

fileName | \- полное имя файла,  
---|---  
saveMode | \- версия для сохранения: -1 - в предыдущую версию, 0 - в текущую версию, 1 - в версию 5.11.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

Если fileName = NULL, то используется имя файла из документа. Если же и в документе отсутствует имя файла, то взводится ошибка.

Подразделы:

(отсутствуют)
