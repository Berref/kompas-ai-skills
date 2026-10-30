# dynamic - Признак динамического запроса

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы видов, слоев, запроса к системе ](cc1711812.html) > [Запрос к системе (Интерфейс ksRequestInfo) ](ksrequestinfo.html) > [RequestInfo - свойства ](ksrequestinfo_props.html) |  Scroll [ [ [ ](ksrequestinfo_menuid.html "К следующему разделу")](ksrequestinfo_props.html "На уровень выше")](ksrequestinfo_cursorid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo.html)

Тип данных:long.

Значения признака:

0 | \- статический запрос,  
---|---  
1 | \- динамический запрос.  
  
Синтаксис Automation:

dynamic = iRequestInfo.dynamic | Получить свойство([* ](1.html))  
---|---  
iRequestInfo.dynamic = dynamic | Установить свойство ([* ](1.html))  
dynamic = iRequestInfo.GetDynamic() | Получить свойство ([**](2.html))  
iRequestInfo.SetDynamic (dynamic) | Установить свойство ([**](2.html))  
  
Примечание:

В случае динамического запроса функция обратной связи вызывается по перемещению курсора. В случае статического запроса функция обратной связи вызывается по щелчку мыши.

Подразделы:

(отсутствуют)
