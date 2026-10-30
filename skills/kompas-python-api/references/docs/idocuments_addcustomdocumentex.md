# AddCustomDocumentEx - Создать новый документ и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Коллекция документов ](ap2013730.html) > [Интерфейс IDocuments ](idocuments.html) > [IDocuments - методы ](idocuments_methods.html) |  Scroll [ [ [ ](idocuments_addnewdocumentfromtemplate.html "К следующему разделу")](idocuments_methods.html "На уровень выше")](idocuments_addcustomdocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocuments.html)

Синтаксис Automation:

LPDISPATCH AddCustomDocumentEx( BSTR DocumentTypeId, BOOL Visible );

Синтаксис COM:

HRESULT AddCustomDocumentEx( BSTR DocumentTypeId, BOOL Visible, IKompasDocument * * Result );

Возвращаемое значение:

указатель на интерфейс [IKompasDocument](ikompasdocument.html) |   
---|---  
  
Входные параметры:

DocumentTypeId | \- идентификатор специализации документа,  
---|---  
Visible | \- TRUE - видимый документ, FALSE - скрытый документ.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
