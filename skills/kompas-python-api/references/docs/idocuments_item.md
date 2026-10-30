# Item - Документ, заданный по имени, ссылке или по индексу

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Коллекция документов ](ap2013730.html) > [Интерфейс IDocuments ](idocuments.html) > [IDocuments - свойства ](idocuments_props.html) |  Scroll [ [ [ ](idocuments_locktemplatessettings.html "К следующему разделу")](idocuments_props.html "На уровень выше")](idocuments_documentsynchronize.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocuments.html)

Тип данных: указатель на интерфейс документа [IKompasDocument](ikompasdocument.html)

Синтаксис Automation:

document = iObject.Item (Index) | Получить свойство([* ](1.html))  
---|---  
document = iObject.GetItem (Index) | Получить свойство([**](2.html))  
  
Синтаксис COM:

iObject->get_IItem ( Index, &Document ) | Получить свойство  
---|---  
  
Входные параметры:

Index | \- Тип VARIANT, полное имя [PathName](ikompasdocument_pathname.html) документа, ссылка на документ или индекс в коллекции.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Полное имя файла документа состоит из пути, имени и расширения файла.

Подразделы:

(отсутствуют)
