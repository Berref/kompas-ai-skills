# IsKompasCommandEnable - Проверить доступность выполнения команды

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - методы ](idocumentframe_methods.html) |  Scroll [ [ [ ](idocumentframe_refreshwindow.html "К следующему разделу")](idocumentframe_methods.html "На уровень выше")](idocumentframe_iskompascommandcheck.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Синтаксис Automation:

BOOL IsKompasCommandEnable (long commandID);

Синтаксис COM:

HRESULT IsKompasCommandEnable (long commandID, BOOL * retVal);

Входные параметры:

commandID | \- константа из перечисления [ProcessTypeEnum](processtypeenum.html) или [ksKompasCommandEnum](kskompascommandenum.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- команда доступна,  
---|---  
FALSE | \- команда недоступна.  
  
Подразделы:

(отсутствуют)
