# AddNewDocumentFromTemplateEx - Создать новый документ по шаблону и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Коллекция документов ](ap2013730.html) > [Интерфейс IDocuments ](idocuments.html) > [IDocuments - методы ](idocuments_methods.html) |  Scroll [ [ [ ](idocuments_addwithdefaultsettings.html "К следующему разделу")](idocuments_methods.html "На уровень выше")](idocuments_addnewdocumentfromtemplate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocuments.html)

Синтаксис Automation:

LPDISPATCH AddNewDocumentFromTemplateEx( BSTR TemplateFileName, BOOL Visible );

Синтаксис COM:

HRESULT AddNewDocumentFromTemplateEx( BSTR TemplateFileName, BOOL Visible, IKompasDocument * * Result );

Возвращаемое значение:

указатель на интерфейс [IKompasDocument](ikompasdocument.html) |   
---|---  
  
Входные параметры:

TemplateFileName | \- путь к файлу шаблона,  
---|---  
Visible | \- TRUE - видимый документ, FALSE - скрытый документ.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
