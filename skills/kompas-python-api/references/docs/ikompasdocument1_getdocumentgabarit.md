# GetDocumentGabarit - Габарит документ

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument1 ](ikompasdocument1.html) > [IKompasDocument1 - методы ](ikompasdocument1_methods.html) |  Scroll [ [ [ ](ikompasdocument1_getexternalfilesnamesex.html "К следующему разделу")](ikompasdocument1_methods.html "На уровень выше")](i_getactivetoolbarset.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument1.html)

Синтаксис Automation:

BOOL GetDocumentGabarit( double * X1, double * Y1, double * X2, double * Y2 );

Синтаксис COM:

HRESULT GetDocumentGabarit( double * X1, double * Y1, double * X2, double * Y2, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

X1, Y1 | \- первая точка габарита - левая нижняя,  
---|---  
X2, Y2 | \- вторая точка габарита - правая верхняя.  
  
Версия Компас v23

Подразделы:

(отсутствуют)
