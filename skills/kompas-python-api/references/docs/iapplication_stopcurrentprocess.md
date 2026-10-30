# StopCurrentProcess - Остановить текущий процесс в документе

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Интерфейс IApplication ](iapplication.html) > [IApplication - методы ](iapplication_methods.html) |  Scroll [ [ [ ](iapplication_events.html "К следующему разделу")](iapplication_methods.html "На уровень выше")](iapplication_quit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplication.html)

Синтаксис Automation:

void StopCurrentProcess (BOOL postMessage, LPDISPATCH pDoc);

Синтаксис COM:

HRESULT StopCurrentProcess([in, defaultvalue(FALSE)]VARIANT_BOOL postMessage, [in, defaultvalue(0)] IKompasDocument* pDoc);

Входные параметры:

postMessage | \- способ остановки процесса,  
---|---  
pDoc | \- указатель на интерфейс [IKompasDocument](ikompasdocument.html), в котором требуется остановить процесс.  
  
Примечание:

1\. Если процесс требуется остановить немедленно, то параметр postMessage должен иметь значение FALSE, однако такая остановка не всегда возможна, например, остановка из обработчика события. В этом случае результат обработки события должен быть обработан процессом; процессу надо сообщить, чтобы он остановился после обработки события. Для этого параметру postMessage нужно установить значение TRUE.

2\. Если параметру pDoc установлено значение 0, то процесс будет остановлен в текущем документе.

Подразделы:

(отсутствуют)
