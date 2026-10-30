# ItemByID - Команда, заданная по идентификатору команды

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс IProcedures ](iprocedures.html) > [IProcedures - свойства ](iprocedures_props.html) |  Scroll [ [ [ ](iprocedureslibraries.html "К следующему разделу")](iprocedures_props.html "На уровень выше")](iprocedures_item.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocedures.html)

Тип данных: указатель на интерфейс [IProcedure](iprocedure.html)

Синтаксис Automation:

Item = iObject.ItemByID (id) | Получить свойство ([* ](1.html))  
---|---  
Item = iObject.GetItemByID (id) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ItemByID (id, &Item) | Получить свойство  
---|---  
  
Входные параметры:

ID (ID) | \- идентификатор команды.  
---|---  
  
Примечание:

Свойство позволяет получить интерфейс библиотечной команды по идентификатору команды в коллекции команд.

Подразделы:

(отсутствуют)
