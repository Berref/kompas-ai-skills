# Item - Команда, заданная по имени или по индексу

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс IProcedures ](iprocedures.html) > [IProcedures - свойства ](iprocedures_props.html) |  Scroll [ [ [ ](iprocedures_itembyid.html "К следующему разделу")](iprocedures_props.html "На уровень выше")](iprocedures_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocedures.html)

Тип данных: указатель на интерфейс [IProcedure](iprocedure.html)

Синтаксис Automation:

Item = iObject.Item (v) | Получить свойство ([* ](1.html))  
---|---  
Item = iObject.GetItem (v) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Item (v. &Item) | Получить свойство  
---|---  
  
Входные параметры:

Index (VARIANT) | Index ( VARIANT ), \- если передано целочисленное значение, то оно интерпретируется как индекс процедуры в коллекции, \- если передано строковое значение, то оно интерпретируется как имя процедуры.  
---|---  
  
Примечание:

Свойство позволяет получить интерфейс библиотечной команды по имени или по индексу в коллекции команд.

Подразделы:

(отсутствуют)
