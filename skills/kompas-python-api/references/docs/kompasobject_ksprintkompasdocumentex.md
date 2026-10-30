# ksPrintKompasDocumentEx - Печать КОМПАС-документа

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksprintpreviewwindow.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksprintkompasdocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksPrintKompasDocumentEx](ksprintkompasdocumentex.html).

Синтаксис Automation:

long ksPrintKompasDocument (BSTR fileName,

BSTR toFile,

double scale,

BOOL fKompasPrinter);

Входные параметры:

fileName | \- полное имя файла печатаемого документа,  
---|---  
toFile | \- имя файла, в который требуется выводить документ (*.prn и т.д.), или NULL, если нужно вывести сразу на принтер,  
scale | \- масштаб вывода,  
fKompasPrint | \- TRUE используем принтер Компас, \- FALSE - умолчательный принтер Windows.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Развитие метода [KompasObject::ksPrintKompasDocument](kompasobject_ksprintkompasdocument.html).

Подразделы:

(отсутствуют)
