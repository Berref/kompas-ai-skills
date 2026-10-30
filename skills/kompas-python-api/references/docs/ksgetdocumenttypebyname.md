# ksGetDocumentTypeByName - Получить тип документа

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Общие функции ](common_docum_fncts.html) |  Scroll [ [ [ ](ksgetdocumenttypebynamew.html "К следующему разделу")](common_docum_fncts.html "На уровень выше")](ksdrawkompasdocumentbyreference.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::GetDocumentTypeByName](kompasobject_ksgetdocumenttypebyname.html).

Синтаксис:

int ksGetDocumentTypeByName (char * fileName);

Входные параметры:

fileName | \- полное имя файла документа.  
---|---  
  
Возвращаемое значение:

int | \- [тип документа](doctype.html),  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Документ при вызове этой функции не создается.

2\. Независимо от используемого оформления возвращается:

– для чертежа - lt_DocSheetStandart,

– для спецификации - lt_DocSpc,

– для текстового документа - lt_DocTxtStandart.

Подразделы:

(отсутствуют)
