# OpenDocument - Открыть документ с заданными параметрами открытия документа

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Коллекция документов ](ap2013730.html) > [Интерфейс IDocuments ](idocuments.html) > [IDocuments - методы ](idocuments_methods.html) |  Scroll [ [ [ ](idocuments_openex.html "К следующему разделу")](idocuments_methods.html "На уровень выше")](idocuments_open.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocuments.html)

Синтаксис Automation:

LPDISPATCH OpenDocument( BSTR FileName, IOpenDocumentParam * Param )

Синтаксис COM:

HRESULT OpenDocument( BSTR FileName, IOpenDocumentParam * Param, IKompasDocument ** Result );

Возвращаемое значение:

Указатель на интерфейс документа [IKompasDocument](ikompasdocument.html)

Входные параметры:

FileName | \- имя файла документа  
---|---  
Param | \- указатель на интерфейс параметров открытия документа [IOpenDocumentParam](iopendocumentparam.html)  
  
Подразделы:

(отсутствуют)
