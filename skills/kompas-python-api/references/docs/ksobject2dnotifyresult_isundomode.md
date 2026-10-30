# IsUndoMode - Признак работы команды Undo

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksObject2DNotifyResultIObject2DNotifyResult ](ksobject2dnotifyresult.html) > [ksObject2DNotifyResult - методы ](ksobject2dnotifyresult_methods.html) |  Scroll [ [ [ ](kspropertymanagernotify.html "К следующему разделу")](ksobject2dnotifyresult_methods.html "На уровень выше")](ksobject2dnotifyresult_isredomode.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobject2dnotifyresult.html)

Синтаксис Automation:

BOOL IsUndoMode();

Синтаксис COM:

BOOL IsUndoMode();

Возвращаемое значение:

TRUE | \- если работает команда Undo.  
---|---  
  
Примечание:

Свойство требуется проверять в событиях, если необходимо отличать событие, полученное от визуальной работы пользователя, от действий, вызванных командой Отменить.

Например, при отмене создания объекта посылается событие удаления объекта.

При отмене удаления объекта посылается событие создания объекта.

См. также: [ksObject2DNotifyResult::IsRedoMode](ksobject2dnotifyresult_isredomode.html)

Подразделы:

(отсутствуют)
