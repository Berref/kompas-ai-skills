# AddWithDefaultSettings - Создать новый документ с параметрами из настроек для новых документов

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Коллекция документов ](ap2013730.html) > [Интерфейс IDocuments ](idocuments.html) > [IDocuments - методы ](idocuments_methods.html) |  Scroll [ [ [ ](idocuments_getembodimentstree.html "К следующему разделу")](idocuments_methods.html "На уровень выше")](idocuments_addnewdocumentfromtemplateex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocuments.html)

Синтаксис Automation:

LPDISPATCH AddWithDefaultSettings( DocumentTypeEnum Type, BOOL Visible );

Синтаксис COM:

HRESULT AddWithDefaultSettings( DocumentTypeEnum Type, BOOL Visible, IKompasDocument** Result );

Входные параметры:

Type | \- тип документа [DocumentTypeEnum](documenttypeenum.html),  
---|---  
Visible | \- TRUE видимый, \- FALSE - невидимый.  
  
Возвращаемое значение:

| индекс линии разрыва,  
---|---  
| указатель на интерфейс [IKompasDocument](ikompasdocument.html).  
  
Подразделы:

(отсутствуют)
