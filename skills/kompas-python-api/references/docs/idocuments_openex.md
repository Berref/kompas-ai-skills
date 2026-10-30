# OpenEx - Открыть документ

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Коллекция документов ](ap2013730.html) > [Интерфейс IDocuments ](idocuments.html) > [IDocuments - методы ](idocuments_methods.html) |  Scroll [ [ [ ](ap1713366.html "К следующему разделу")](idocuments_methods.html "На уровень выше")](idocuments_opendocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocuments.html)

Синтаксис Automation:

LPDISPATCH OpenEx (LPCTSTR PathName, BOOL Visible, BOOL ReadOnly, VARIANT LoadCombinationIndex);

Синтаксис COM:

HRESULT OpenEx([in] BSTR PathName, [in, defaultvalue(TRUE)] VARIANT_BOOL Visible, [in, defaultvalue(FALSE)] VARIANT_BOOL ReadOnly, [in]VARIANT LoadCombinationIndex, [out, retval] IKompasDocument** Result);

Входные параметры:

PathName | \- полное имя файла документа, состоящее из пути, имени и расширения файла,  
---|---  
Visible | \- видимость документа: TRUE создавать документ в видимом режиме, FALSE в невидимом,  
ReadOnly | \- TRUE - открыть документ только для чтения,  
LoadCombinationIndex | \- тип VARIANT - индекс загружаемого набора или имя набора.  
  
Возвращаемое значение:

указатель на интерфейс [IKompasDocument](ikompasdocument.html) | \- в случае успешного завершения,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание:

1\. Открывает существующий документ и добавляет его в коллекцию.

2\. Для сборки 3D можно задать индекс набора для загрузки. Для других типов документов индекс загружаемого набора игнорируется.

Подразделы:

(отсутствуют)
