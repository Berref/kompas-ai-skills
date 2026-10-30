# ExecuteProcessOfDocumentFromFile - Запустить процесс вставки документа из файла или библиотеки документов

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_gethyperlinkobjects.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_destroyobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL ExecuteProcessOfDocumentFromFile( BSTR FileName, ProcessTypeEnum ProcessType );

Синтаксис COM:

HRESULT ExecuteProcessOfDocumentFromFile( BSTR FileName, ProcessTypeEnum ProcessType, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

FileName | \- имя файла,  
---|---  
ProcessType | \- тип процесса из перечисления [ProcessTypeEnum](processtypeenum.html).  
  
Версия Компас v23

Подразделы:

(отсутствуют)
