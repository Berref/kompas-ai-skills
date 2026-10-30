# cursor - Cтрока с именем стандартного курсора

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы видов, слоев, запроса к системе ](cc1711812.html) > [Запрос к системе (Интерфейс ksRequestInfo) ](ksrequestinfo.html) > [RequestInfo - свойства ](ksrequestinfo_props.html) |  Scroll [ [ [ ](ksrequestinfo_cursorid.html "К следующему разделу")](ksrequestinfo_props.html "На уровень выше")](ksrequestinfo_commandsstring.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo.html)

Тип данных:строка.

Синтаксис Automation:

cursor = iRequestInfo.cursor | Получить свойство([* ](1.html))  
---|---  
iRequestInfo.cursor = cursor | Установить свойство ([* ](1.html))  
cursor = iRequestInfo.GetCursor() | Получить свойство ([**](2.html))  
iRequestInfo.SetCursor (cursor) | Установить свойство ([**](2.html))  
  
Примечание:

Кроме стандартных констант из WINUSER.H можно использовать стандартные курсоры системы КОМПАС (ldefin2d.h):

![cursor_select](./images/cursor_select.jpg) OCR_SELECT

![cursor_snap](./images/cursor_snap.jpg) OCR_SNAP

![POINT_NONUM](./images/point_nonum.jpg) OCR_DEFAULT

![cursor_catch](./images/cursor_catch.jpg) OCR_CATCH

Подразделы:

(отсутствуют)
