# ksPrintKompasDocumentW - Напечатать КОМПАС-документ (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Функции вывода на печать ](print_docum_fncts.html) |  Scroll [ [ [ ](ksprintkompasdocumentex.html "К следующему разделу")](print_docum_fncts.html "На уровень выше")](ksprintkompasdocument.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksPrintKompasDocument](kompasobject_ksprintkompasdocument.html).

Синтаксис:

int LIB_FUNC ksPrintKompasDocumentW( LPCWSTR fileName,

LPCWSTR toFile,

double scale);

Входные параметры:

fileName | \- полное имя файла печатаемого документа,  
---|---  
toFile | \- имя файла, в который требуется выводить документ (*.prn и т.д.), или NULL, если нужно вывести сразу на принтер,  
scale | \- масштаб вывода.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании ANSI следует использовать функцию [ksPrintKompasDocument](ksprintkompasdocument.html).

Подразделы:

(отсутствуют)
