# ksPrintKompasDocumentExW - Напечатать КОМПАС-документ (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Функции вывода на печать ](print_docum_fncts.html) |  Scroll [ [ [ ](doc_tunes_fncts.html "К следующему разделу")](print_docum_fncts.html "На уровень выше")](ksprintkompasdocumentex.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksPrintKompasDocumentEx](kompasobject_ksprintkompasdocumentex.html).

Синтаксис:

int ksPrintKompasDocumentEx( LPCWSTR fileName,

LPCWSTR toFile,

double scale,

int fKompasPrinter );

Входные параметры:

fileName | \- полное имя файла печатаемого документа,  
---|---  
toFile | \- имя файла, в который требуется выводить документ (*.prn и т.д.), или NULL, если нужно вывести сразу на принтер,  
Scale | \- масштаб вывода,  
fKompasPrint | \- TRUE - используем принтер Компас, \- FALSE - умолчательный принтер Windows.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

1\. При использовании ANSI следует использовать функцию [ksPrintKompasDocumentEx](ksprintkompasdocumentex.html).

2\. Функция является развитием [ksPrintKompasDocumentW](ksprintkompasdocumentw.html).

Подразделы:

(отсутствуют)
