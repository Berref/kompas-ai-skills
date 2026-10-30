# ksOpenDocument - Открыть документ

[API интерфейсов. Версия 5](ag57940.html) > [Текстовый документ (Интерфейс ksDocumentTxt) ](ksdocumenttxt.html) > [ksDocumentTxt - методы ](ksdocumenttxt_methods.html) |  Scroll [ [ [ ](ksdocumenttxt_kssavedocument.html "К следующему разделу")](ksdocumenttxt_methods.html "На уровень выше")](ksdocumenttxt_ksgetobjparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumenttxt.html)

Аналог данного метода при использовании API экспортных функций - [OpenDocument](opendocument.html).

Синтаксис Automation:

BOOL ksOpenDocument (BSTR nameDoc, BOOL regim);

Входные параметры:

nameDoc | \- имя документа,  
---|---  
regim | \- режим работы с документом: 0 - видимый, 1 - невидимый ("слепой").  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

1\. Невидимый режим применяется при пакетном (скрытом) формировании документа.

2\. Открытый документ автоматически становится текущим.

Подразделы:

(отсутствуют)
