# cursorName - Имя курсора

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [IRequestInfo - свойства ](ksrequestinfo3d_props.html) |  Scroll [ [ [ ](ksrequestinfo3d_dynamicfiltering.html "К следующему разделу")](ksrequestinfo3d_props.html "На уровень выше")](ksrequestinfo3d_cursorid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrequestinfo3d.html)

Аналог данного свойства при использовании COM - методы [IRequestInfo::GetCursorName](irequestinfo_getcursorname.html) и [IRequestInfo::SetCursorNameString](irequestinfo_setcursorname.html).

Тип данных: строка

Синтаксис Automation:

cursorName = IRequestInfo.cursorName | Получить свойство ([* ](1.html))  
---|---  
IRequestInfo.cursorName = cursorName | Установить свойство ([* ](1.html))  
cursorName = IRequestInfo.GetCursorName() | Получить свойство ([**](2.html))  
IRequestInfo.SetCursorName(cursorName) | Установить свойство ([**](2.html))  
  
Примечание:

Кроме стандартных констант из WINUSER.H можно использовать стандартные курсоры системы КОМПАС (ldefin2d.h):

![cursor_select](./images/cursor_select.jpg) OCR_SELECT

![cursor_snap](./images/cursor_snap.jpg) OCR_SNAP

![POINT_NONUM](./images/point_nonum.jpg) OCR_DEFAULT

![cursor_catch](./images/cursor_catch.jpg) OCR_CATCH

Подразделы:

(отсутствуют)
