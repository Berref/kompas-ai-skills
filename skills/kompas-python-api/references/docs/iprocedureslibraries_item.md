# Item - Прикладная библиотека, заданная по имени или по индексу

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс IProceduresLibraries ](iprocedureslibraries.html) > [IProceduresLibraries - свойства ](iprocedureslibraries_props.html) |  Scroll [ [ [ ](iprocedureslibraries_methods.html "К следующему разделу")](iprocedureslibraries_props.html "На уровень выше")](iprocedureslibraries_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocedureslibraries.html)

Тип данных: указатель на интерфейс [IProceduresLibrary](iprocedureslibrary.html)

Синтаксис Automation:

Item = iObject.Item (v) | Получить свойство ([* ](1.html))  
---|---  
Item = iObject.GetItem (v) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Item (v, &Item) | Получить свойство  
---|---  
  
Входные параметры:

v (VARIANT) | \- если передано целочисленное значение, то оно интерпретируется как индекс библиотеки в коллекции, \- если передано строковое значение, то оно интерпретируется как имя библиотеки.  
---|---  
  
Примечание:

Свойство позволяет получить интерфейс прикладной библиотеки по имени библиотеки или по индексу библиотеки в коллекции библиотек.

Подразделы:

(отсутствуют)
