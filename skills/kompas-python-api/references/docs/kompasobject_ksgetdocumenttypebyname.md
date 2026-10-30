# ksGetDocumentTypeByName - Получить тип документа DocType

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksgetselectedembodimentmarking.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksgetdocumenttypebynameex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Получить тип документа [DocType](doctype.html)

Аналог данного метода при использовании API экспортных функций - [ksGetDocumentTypeByName](ksgetdocumenttypebyname.html).

Синтаксис Automation:

long ksGetDocumentTypeByName (BSTR fileName);

Входной параметр:

(BSTR) fileName | \- полное имя файла документа.  
---|---  
  
Возвращаемое значение:

тип документа DocType "ldefin2d.h" | \- при успешном завершении,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Документ при вызове этой функции не создается.

2\. Независимо от используемого оформления возвращается:

для чертежа | lt_DocSheetStandart  
---|---  
для спецификации | lt_DocSpc  
для текстового документа | lt_DocTxtStandart  
  
Подразделы:

(отсутствуют)
