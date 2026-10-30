# AddDocument - Добавляет новый документ к объекту спецификации и в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс IAttachedDocuments ](iattacheddocuments.html) > [IAttachedDocuments - методы ](iattacheddocuments_methods.html) |  Scroll [ [ [ ](ispecificationbaseobjects.html "К следующему разделу")](iattacheddocuments_methods.html "На уровень выше")](iattacheddocuments_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattacheddocuments.html)

Синтаксис Automation:

LPDISPATCH AddDocument( BSTR Name, BOOL Transmit, BOOL FillText, BSTR

Синтаксис COM:

HRESULT AddDocument( BSTR Name, BOOL Transmit, BOOL FillText, BSTR

** Result);

Возвращаемое значение:

| \- указатель на интерфейс [IAttachedDocumen](iattacheddocument.html)t присоединенного документа.  
---|---  
  
Входные параметры:

Name | \- полное имя присоединяемого документа,  
---|---  
Transmit | \- передавать изменения в документ,  
FillText | \- взять данные из документа в объект спецификации,  
EmbodimentMarking | \- имя подключаемого исполнения.  
  
Подразделы:

(отсутствуют)
