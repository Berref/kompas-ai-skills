# IsKompasCommandCheck - Проверить, нажата ли кнопка команды

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - методы ](idocumentframe_methods.html) |  Scroll [ [ [ ](idocumentframe_iskompascommandenable.html "К следующему разделу")](idocumentframe_methods.html "На уровень выше")](idocumentframe_getzoomscale.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Синтаксис Automation:

long IsKompasCommandCheck (long commandID);

Синтаксис COM:

HRESULT IsKompasCommandCheck (long commandID, long * retVal);

Входные параметры:

commandID | \- константа из перечисления [ProcessTypeEnum](processtypeenum.html) или [ksKompasCommandEnum](kskompascommandenum.html).  
---|---  
  
Возвращаемое значение:

1 | \- кнопка нажата,  
---|---  
0 | \- кнопка отжата.  
  
Подразделы:

(отсутствуют)
