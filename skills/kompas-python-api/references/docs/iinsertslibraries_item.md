# Item - Элемент, заданный по имени или по индексу

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс IInsertsLibraries ](iinsertslibraries.html) > [IInsertsLibraries - свойства ](iinsertslibraries_props.html) |  Scroll [ [ [ ](iinsertslibraries_methods.html "К следующему разделу")](iinsertslibraries_props.html "На уровень выше")](iinsertslibraries_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinsertslibraries.html)

Тип данных: указатель на интерфейс [IInsertsLibrary](iinsertslibrary.html)

Синтаксис Automation:

Item = iObject.Item (v) | Получить свойство ([* ](1.html))  
---|---  
Item = iObject.GetItem (v) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Item (v. &Item) | Получить свойство  
---|---  
  
Входные параметры:

Index (VARIANT) | \- если передано целочисленное значение, то оно интерпретируется как индекс библиотеки в коллекции, \- если передано строковое значение, то оно интерпретируется как имя библиотеки.  
---|---  
  
Примечание:

Свойство позволяет получить интерфейс библиотеки документов по имени библиотеки или по индексу библиотеки в коллекции библиотек.

Подразделы:

(отсутствуют)
