# ksSaveDocumentEx - Сохранить документ в выбранной версии

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Оформление чертежа ](bt1730281.html) |  Scroll [ [ [ ](ksdocument2d_kssetdocoptions.html "К следующему разделу")](bt1730281.html "На уровень выше")](ksdocument2d_kssavedocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [SaveDocumentEx](savedocumentex.html).

Синтаксис Automation:

BOOL ksSaveDocumentEx (BSTR fileName, long version);

Входные параметры:

fileName | \- полное имя файла,  
---|---  
version | \- версия для сохранения: -1 - в предыдущую версию, 0 - в текущую версию, 1 - в версию 5.11.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Если fileName = NULL, то используется имя файла из документа. Если же и в документе отсутствует имя файла, то взводится ошибка.

Подразделы:

(отсутствуют)
