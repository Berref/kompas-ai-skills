# Add - Добавить новый документ к объекту спецификации и в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс IAttachedDocuments ](iattacheddocuments.html) > [IAttachedDocuments - методы ](iattacheddocuments_methods.html) |  Scroll [ [ [ ](iattacheddocuments_adddocument.html "К следующему разделу")](iattacheddocuments_methods.html "На уровень выше")](iattacheddocuments_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattacheddocuments.html)

Синтаксис Automation:

LPDISPATCH Add( BSTR Name, BOOL transmit );

Синтаксис COM:

HRESULT Add ( [in] BSTR Name,

[in] BOOL transmit,

[out, retval] IAttachedDocument** Result );

Входные параметры:

Name | \- полное имя файла присоединяемого документа,  
---|---  
transmit | \- передавать изменения в документ.  
  
Возвращаемое значение:

| \- указатель на интерфейс [IAttachedDocument](iattacheddocument.html) присоединенного документа.  
---|---  
  
Примечание:

1\. После вызова метода Add документ будет добавлен в коллекцию.

2\. Для удаления документа из коллекции используется метод [IAttachedDocument::Delete](iattacheddocument_delete.html)

3\. После добавления нужных документов вызвать метод [ISpecificationObject::Update](ispecificationobject_update.html).

4\. В результате подключения документа в соответствующие колонки объекта спецификации автоматически будут переданы наименование и обозначение из модели или основной надписи чертежа, а также обозначение формата, на котором выполнен подключенный чертеж.

5\. Информация из подключенного документа может передаваться не только в колонки бланка спецификации, но и в дополнительные колонки. Например, в дополнительную колонку объекта может быть автоматически передана масса детали из модели или из соответствующей графы основной надписи.

Подразделы:

(отсутствуют)
