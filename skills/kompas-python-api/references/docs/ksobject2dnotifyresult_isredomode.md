# IsRedoMode - Признак работы команды Redo

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksObject2DNotifyResultIObject2DNotifyResult ](ksobject2dnotifyresult.html) > [ksObject2DNotifyResult - методы ](ksobject2dnotifyresult_methods.html) |  Scroll [ [ [ ](ksobject2dnotifyresult_isundomode.html "К следующему разделу")](ksobject2dnotifyresult_methods.html "На уровень выше")](ksobject2dnotifyresult_iscopy.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobject2dnotifyresult.html)

Синтаксис Automation:

BOOL IsRedoMode();

Синтаксис COM:

BOOL IsRedoMode();

Возвращаемое значение:

TRUE | \- если работает команда Redo.  
---|---  
  
Примечание:

Свойство требуется проверять в событиях, если необходимо отличать событие, полученное от визуальной работы пользователя, от действий, вызванных командой Повторить (т.е. вернуть отмененное действие).

См. также: [ksObject2DNotifyResult::IsUndoMode](ksobject2dnotifyresult_isundomode.html)

Подразделы:

(отсутствуют)
