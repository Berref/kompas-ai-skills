# RequestInfo - Структура параметров запроса к системе

[Структуры параметров и константы](3d_define.html) > [Структуры параметров системы ](bk1803366.html) |  Scroll [ [ [ ](structrequestinfow.html "К следующему разделу")](bk1803366.html "На уровень выше")](structltvariantex.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksRequestInfo](ksrequestinfo.html).

char | *title | строка или идентификатор строки заголовка окна,  
---|---|---  
char | *commands | строка или идентификатор меню состава команд,  
char | *prompt | строка или идентификатор приглашения,  
char | *cursor | строка с именем или идентификатор стандартного курсора,  
void | *callBack | указатель на функцию обратной связи,  
int | dynamic | признак динамического запроса (1 - динамический запрос, 0 - статический),  
HINSTANCE | commInstance | идентификатор модуля, в котором размещен состав команд.  
  
Примечание:

1\. Эта структура используется в функциях [Cursor](cursor.html), [Placement](placement.html), [CommandWindow](commandwindow.html).

2\. В случае динамического запроса функция обратной связи вызывается по перемещению курсора. В случае статического запроса функция обратной связи вызывается по щелчку мыши.

3\. Кроме стандартных констант из WINUSER.H можно использовать стандартные курсоры системы КОМПАС (ldefin2d.h):

![cursor_select](./images/cursor_select.jpg) OCR_SELECT

![cursor_snap](./images/cursor_snap.jpg) OCR_SNAP

![POINT_NONUM](./images/point_nonum.jpg) OCR_DEFAULT

![cursor_catch](./images/cursor_catch.jpg) OCR_CATCH

Подразделы:

(отсутствуют)
