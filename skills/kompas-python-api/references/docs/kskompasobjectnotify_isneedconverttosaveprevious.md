# IsNeedConvertToSavePrevious - Начало сохранения документа в предыдущую верcию

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify.html) > [ksKompasObjectNotify - события ](kskompasobjectnotify_events.html) |  Scroll [ [ [ ](kskompasobjectnotify_keydown.html "К следующему разделу")](kskompasobjectnotify_events.html "На уровень выше")](kskompasobjectnotify_endconverttosaveprevious.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompasobjectnotify.html)

Синтаксис Automation:

BOOL IsNeedConvertToSavePrevious( LPDISPATCH pDoc, long docType, long saveVersion, LPDISPATCH saveToPreviusParam, BOOL * needConvert );

Синтаксис COM:

BOOL IsNeedConvertToSavePrevious( long pDoc, long docType, long saveVersion, LPUNKNOWN saveToPreviusParam, BOOL * needConvert );

Возвращаемое значение:

| \- Не используется.  
---|---  
  
Входные параметры

pDoc | \- документ,  
---|---  
docType | \- тип документа,  
saveVersion | \- версия сохранения документа из перечисления [ksSaveDocumentVersionEnum](kssavedocumentversionenum.html),  
saveToPreviusParam | \- параметры конвертации при сохранении в предыдущую версию [ISaveToPreviusParam](isavetopreviusparam.html)\ksSaveToPreviusParam.  
  
Выходной параметр:

needConvert | \- требуется вернуть TRUE, если для сохранения в предыдущую версию требуется конвертация документа.  
---|---  
  
Подразделы:

(отсутствуют)
