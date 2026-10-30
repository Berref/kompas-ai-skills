# ksGetTxtDocumentPagesCount - Получить количество листов текстового документа

[API экспортных функций](export_function.html) > [Функции работы с текстовым документом ](cn1724036.html) |  Scroll [ [ [ ](work_with_files_common.html "К следующему разделу")](cn1724036.html "На уровень выше")](createtextdocumentw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocumentTxt::GetTxtDocumentPagesCount](ksdocumenttxt_gettxtdocumentpagescount.html).

Синтаксис:

int ksGetTxtDocumentPagesCount (reference txtDoc);

Входные параметры:

txtDoc | \- указатель на текстовый документ.  
---|---  
  
Возвращаемое значение:

количество листов | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если txtDoc=0 - возвращается количество листов текущего текстового документа.

Подразделы:

(отсутствуют)
