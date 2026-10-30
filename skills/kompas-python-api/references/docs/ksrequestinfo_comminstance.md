# commInstance - Идентификатор приложения (dll), в котором размещены ресурсы процесса

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы видов, слоев, запроса к системе ](cc1711812.html) > [Запрос к системе (Интерфейс ksRequestInfo) ](ksrequestinfo.html) > [RequestInfo - свойства ](ksrequestinfo_props.html) |  Scroll [ [ [ ](ksrequestinfo_comminstanceex.html "К следующему разделу")](ksrequestinfo_props.html "На уровень выше")](ksrequestinfo_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo.html)

Тип данных:long.

Синтаксис Automation:

commInstance = iRequestInfo.commInstance | Получить свойство([* ](1.html))  
---|---  
iRequestInfo.commInstance = commInstance | Установить свойство ([* ](1.html))  
commInstance = iRequestInfo.GetCommInstance() | Получить свойство ([**](2.html))  
iRequestInfo.SetCommInstance (commInstance) | Установить свойство ([**](2.html))  
  
Примечание:

Функция устарела. Использование данной функции может привести к ошибке в библиотеке, собранной с конфигурацией x64.

Рекомендуется использовать функцию [ksRequestInfo::commInstanceEx](ksrequestinfo_comminstanceex.html).

Подразделы:

(отсутствуют)
