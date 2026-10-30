# CreateTextDocumentW - Создать текстовый документ (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с текстовым документом ](cn1724036.html) |  Scroll [ [ [ ](ksgettxtdocumentpagescount.html "К следующему разделу")](cn1724036.html "На уровень выше")](createtextdocument.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocumentTxt::ksCreateDocument](ksdocumenttxt_kscreatedocument.html).

Синтаксис:

reference LIB_FUNC CreateTextDocumentW (TextDocumentParamW * par);

Входные параметры:

par | [\- указатель на структуру параметров ](structtextdocumentparam.html)[TextDocumentParam](structtextdocumentparam.html).  
---|---  
  
Возвращаемое значение:

указатель на документ | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Документ становится текущим (видимым или невидимым).

2\. Задается полное имя файла.

3\. При использовании ANSI следует использовать функцию [CreateTextDocument](createtextdocument.html).

Подразделы:

(отсутствуют)
