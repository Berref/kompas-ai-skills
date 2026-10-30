# cursorId - Идентификатор курсора

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [IRequestInfo - свойства ](ksrequestinfo3d_props.html) |  Scroll [ [ [ ](ksrequestinfo3d_cursorname.html "К следующему разделу")](ksrequestinfo3d_props.html "На уровень выше")](ksrequestinfo3d_commandsstring.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo3d.html)

Аналог данного свойства при использовании COM - методы [IRequestInfo::GetCursorId](irequestinfo_getcursorid.html) и [IRequestInfo::SetCursorIdString](irequestinfo_setcursorid.html).

Тип данных: long

Синтаксис Automation:

cursorId = IRequestInfo.cursorId | Получить свойство ([* ](1.html))  
---|---  
IRequestInfo.cursorId = cursorId | Установить свойство ([* ](1.html))  
cursorId = IRequestInfo.GetCursorId() | Получить свойство ([**](2.html))  
IRequestInfo.SetCursorId(cursorId) | Установить свойство ([**](2.html))  
  
Примечание:

Кроме стандартных констант из WINUSER.H можно использовать стандартные курсоры системы КОМПАС (ldefin2d.h):

![cursor_select](./images/cursor_select.jpg) OCR_SELECT

![cursor_snap](./images/cursor_snap.jpg) OCR_SNAP

![POINT_NONUM](./images/point_nonum.jpg) OCR_DEFAULT

![cursor_catch](./images/cursor_catch.jpg) OCR_CATCH

Подразделы:

(отсутствуют)
