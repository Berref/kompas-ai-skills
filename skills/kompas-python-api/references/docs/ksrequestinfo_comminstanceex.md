# commInstanceEx - Идентификатор приложения (dll), в котором размещены ресурсы процесса

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы видов, слоев, запроса к системе ](cc1711812.html) > [Запрос к системе (Интерфейс ksRequestInfo) ](ksrequestinfo.html) > [RequestInfo - свойства ](ksrequestinfo_props.html) |  Scroll [ [ [ ](ksrequestinfo_commandsstring.html "К следующему разделу")](ksrequestinfo_props.html "На уровень выше")](ksrequestinfo_comminstance.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksrequestinfo.html).

Тип данных: VARIANT.

Синтаксис Automation:

commInstance = Object.commInstanceEx | Получить свойство([* ](1.html))  
---|---  
Object.commInstanceEx = commInstance | Установить свойство ([* ](1.html))  
commInstance = Object.GetCommInstanceEx() | Получить свойство ([**](2.html))  
Object.SetCommInstanceEx( commInstance ) | Установить свойство ([**](2.html))  
  
Примечание:

HINSTANCE библиотеки нужно передать через VARIANT, как VT_I4 в Win32 и VT_I8 в x64.

Для правильного формирования _variant_t HINSTANCE нужно передавать через приведение к (LONG_PTR).

В библиотеках, использующих автоматизацию, рекомендуется использовать данное свойство вместо [ksRequestInfo::commInstance](ksrequestinfo_comminstance.html).

Подразделы:

(отсутствуют)
