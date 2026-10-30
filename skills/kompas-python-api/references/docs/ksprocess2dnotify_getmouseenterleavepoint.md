# GetMouseEnterLeavePoint - Запрос параметров точек для визуального определения места применения параметра

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksProcess2DNotify\IProcess2DNotify ](ksprocess2dnotify.html) > [События ](ksprocess2dnotify_events.html) |  Scroll [ [ [ ](ksprocess2dnotify_endprocess.html "К следующему разделу")](ksprocess2dnotify_events.html "На уровень выше")](ksprocess2dnotify_deactivate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksprocess2dnotify.html)

Синтаксис Automation:

BOOL GetMouseEnterLeavePoint( LPDISPATCH Control, long BtnID, long PointIndex, LPDISPATCH Parameters );

Синтаксис COM:

BOOL GetMouseEnterLeavePoint( LPUNKNOWN control, long btnID, long pointIndex, LPUNKNOWN parameters );

Входные параметры:

index | \- индекс стандартного или пользовательского набора загрузки.  
---|---  
  
Возвращаемое значение:

Не используется

Примечание

У сборки есть умолчательные стандартные наборы, индексы которых соответствуют перечислению [ksLoadStateEnum](ksloadstateenum.html). Кроме этого могут быть еще и пользовательские наборы.

Подразделы:

(отсутствуют)
