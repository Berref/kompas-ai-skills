# ExecuteKompasCommand - Выполнить команду системы КОМПАС

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - методы ](idocumentframe_methods.html) |  Scroll [ [ [ ](idocumentframe_gethwnd.html "К следующему разделу")](idocumentframe_methods.html "На уровень выше")](idocumentframe_convertcoordinates.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Синтаксис Automation:

BOOL ExecuteKompasCommand (long commandID, BOOL post);

Синтаксис COM:

HRESULT ExecuteKompasCommand (long commandID, BOOL post, BOOL * retval);

Входные параметры:

commandID | \- константа из перечисления [ProcessTypeEnum](processtypeenum.html) или [ksKompasCommandEnum](kskompascommandenum.html),  
---|---  
post | \- true - запуск команды через PostMessage, \- false - через SendMessage.  
  
Возвращаемое значение:

TRUE | \- в случае удачи,  
---|---  
FALSE | \- в случае ошибки.  
  
Примечание:

1\. Проверить доступность команды можно с помощью функции [IDocumentFrame::IsKompasCommandEnable](idocumentframe_iskompascommandenable.html).

2\. Проверить, нажата ли в данный момент кнопка команды, можно с помощью [IDocumentFrame::IsKompasCommandCheck](idocumentframe_iskompascommandcheck.html).

Подразделы:

(отсутствуют)
