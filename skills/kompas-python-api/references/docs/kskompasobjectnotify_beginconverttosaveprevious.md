# BeginConvertToSavePrevious - Начало конвертации документа перед записью в предыдущую версию

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify.html) > [ksKompasObjectNotify - события ](kskompasobjectnotify_events.html) |  Scroll [ [ [ ](kskompasobjectnotify_begincreate.html "К следующему разделу")](kskompasobjectnotify_events.html "На уровень выше")](kskompasobjectnotify_beginclosealldocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompasobjectnotify.html)

Синтаксис Automation:

BOOL BeginConvertToSavePrevious( LPDISPATCH pDoc, long docType, long saveVersion, LPDISPATCH saveToPreviusParam );

Синтаксис COM:

BOOL BeginConvertToSavePrevious( long pDoc, long docType, long saveVersion, LPUNKNOWN saveToPreviusParam );

Возвращаемое значение:

| \- Не используется.  
---|---  
  
Входные параметры:

pDoc | \- документ,  
---|---  
docType | \- тип документа.  
saveVersion | \- версия сохранения документа из перечисления [ksSaveDocumentVersionEnum](kssavedocumentversionenum.html),  
saveToPreviusParam | \- параметры конвертации при сохранении в предыдущую версию [ISaveToPreviusParam](isavetopreviusparam.html)\ksSaveToPreviusParam.  
  
Подразделы:

(отсутствуют)
