# Add - Создать новый документ и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Коллекция документов ](ap2013730.html) > [Интерфейс IDocuments ](idocuments.html) > [IDocuments - методы ](idocuments_methods.html) |  Scroll [ [ [ ](idocuments_addcustomdocument.html "К следующему разделу")](idocuments_methods.html "На уровень выше")](idocuments_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocuments.html)

Синтаксис Automation:

LPDISPATCH Add (long Type, BOOL Visible);

Синтаксис COM:

HRESULT Add([in] DocumentTypeEnum Type, [in, defaultvalue(TRUE)] VARIANT_BOOL Visible, [out, retval] IKompasDocument** Result);

Входные параметры:

Type | \- тип документа из перечисления [DocumentTypeEnum](documenttypeenum.html),  
---|---  
Visible | \- видимость документа: TRUE создавать документ в видимом режиме, FALSE в слепом.  
  
Возвращаемое значение:

указатель на интерфейс [IKompasDocument](ikompasdocument.html) |   
---|---  
  
Подразделы:

(отсутствуют)
