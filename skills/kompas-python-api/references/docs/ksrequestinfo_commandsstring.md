# commandsString - Cтрока меню состава команд

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы видов, слоев, запроса к системе ](cc1711812.html) > [Запрос к системе (Интерфейс ksRequestInfo) ](ksrequestinfo.html) > [RequestInfo - свойства ](ksrequestinfo_props.html) |  Scroll [ [ [ ](ksrequestinfo_cursor.html "К следующему разделу")](ksrequestinfo_props.html "На уровень выше")](ksrequestinfo_comminstanceex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksrequestinfo.html).

Тип данных:строка.

Синтаксис Automation:

commandsString = iRequestInfo.commandsString | Получить свойство([* ](1.html))  
---|---  
iRequestInfo.commandsString = commandsString | Установить свойство ([* ](1.html))  
commandsString = iRequestInfo.GetCommandsString() | Получить свойство ([**](2.html))  
iRequestInfo.SetCommandsString (commandsString) | Установить свойство ([**](2.html))  
  
Примечание:

Это свойство позволяет сформировать одноуровневое меню (без вложенных пунктов).

Восклицательный знак разделяет пункты меню, например, "!Квадрат !Треугольник !Ромб".

Подразделы:

(отсутствуют)
