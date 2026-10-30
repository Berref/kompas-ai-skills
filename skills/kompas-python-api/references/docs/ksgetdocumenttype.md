# ksGetDocumentType - Получить тип документа

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Общие функции ](common_docum_fncts.html) |  Scroll [ [ [ ](ksdrawkompasdocumentbyreference.html "К следующему разделу")](common_docum_fncts.html "На уровень выше")](setdocoptions.html "К предыдущему разделу")  
---|---  
  
[Аналог данной функции при использовании Automation - метод ](ksdocument2d_ksgetdocumenttype.html)[ksDocument2D::ksGetDocumentType](ksdocument2d_ksgetdocumenttype.html).

Синтаксис:

int ksGetDocumentType (reference doc);

Входные параметры:

doc | \- указатель на документ.  
---|---  
  
Возвращаемое значение:

[тип документа](doctype.html) | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если указатель doc = 0, возвращается тип активного документа.

Подразделы:

(отсутствуют)
