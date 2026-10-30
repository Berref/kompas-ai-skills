# Open - Открыть документ

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Коллекция документов ](ap2013730.html) > [Интерфейс IDocuments ](idocuments.html) > [IDocuments - методы ](idocuments_methods.html) |  Scroll [ [ [ ](idocuments_opendocument.html "К следующему разделу")](idocuments_methods.html "На уровень выше")](idocuments_getopendocumentparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocuments.html)

Синтаксис Automation:

LPDISPATCH Open (LPCTSTR PathName, BOOL Visible, BOOL ReadOnly);

Синтаксис COM:

HRESULT Open([in] BSTR PathName, [in, defaultvalue(TRUE)] VARIANT_BOOL Visible, [in, defaultvalue(FALSE)] VARIANT_BOOL ReadOnly, [out, retval] IKompasDocument** Result);

Входные параметры:

PathName | \- полное имя файла документа, состоящее из пути, имени и расширения файла,  
---|---  
Visible | \- видимость документа: TRUE создавать документ в видимом режиме, FALSE в невидимом,  
ReadOnly | \- TRUE - открыть документ только для чтения.  
  
Возвращаемое значение:

указатель на интерфейс [IKompasDocument](ikompasdocument.html) | \- в случае успешного завершения,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание:

Открывает существующий документ и добавляет его в коллекцию.

Подразделы:

(отсутствуют)
