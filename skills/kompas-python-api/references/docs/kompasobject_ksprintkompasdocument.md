# ksPrintKompasDocument - Печать КОМПАС-документа

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksprintkompasdocumentex.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksmodule3d.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Аналог данного метода при использовании API экспортных функций - [ksPrintKompasDocument](ksprintkompasdocument.html).

Синтаксис Automation:

long ksPrintKompasDocument (BSTR fileName,

BSTR toFile,

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
  
Подразделы:

(отсутствуют)
