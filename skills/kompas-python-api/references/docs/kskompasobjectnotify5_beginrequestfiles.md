# BeginRequestFiles - Запрос имен файлов

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий приложения ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify5.html) > [ksKompasObjectNotify, IKompasObjectNotify - события ](kskompasobjectnotify5_events_.html) |  Scroll [ [ [ ](kskompasobjectnotify5_changeactivedocument.html "К следующему разделу")](kskompasobjectnotify5_events_.html "На уровень выше")](kskompasobjectnotify5_beginopenfile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompasobjectnotify.html)

Синтаксис Automation:

BOOL BeginRequestFiles( long requestID, VARIANT * files );

Синтаксис COM:

BOOL BeginRequestFiles( long requestID, VARIANT * files );

Входные параметры:

requestID | \- тип запроса файлов из перечисления [ksRequestFilesTypeEnum](ksrequestfilestypeenum.html).  
---|---  
  
Выходные параметры:

files | \- имя файла или список SafeArray файлов.  
---|---  
  
Возвращаемое значение:

TRUE | \- использовать стандартный диалог выбора файлов,  
---|---  
FALSE | \- если список файлов задан - использовать файл или файлы из списка, если список файлов не задан - отмена выбора файлов.  
  
Примечание:

1\. Если выбран один файл, то в VARIANT его имя можно положить как строку, тип VARIANT-а - VT_BSTR. Если выбрано несколько файлов, то их имена в VARIANT нужно положить как массив строк тип VARIANT-а - VT_ARRAY | VT_BSTR.

2\. Возможность множественного выбора и допустимые расширения файлов зависят от типа запроса файлов.

3\. В данных событиях в отличие от других событий начала какого либо действия требуется обработка трех состояний:

•отказ пользователя или обработка события выполнена полностью на стороне библиотеки - событие возвращает FALSE;

•событие возвращает TRUE и имя файла для продолжения выполнения команды - процесс продолжается без запуска диалога выбора файла или файлов;

•событие возвращает TRUE, но имя файла не возвращается - запускается стандартный диалог выбора файла из системы КОМПАС.

Подразделы:

(отсутствуют)
