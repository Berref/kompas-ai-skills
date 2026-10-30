# Delete - Завершение удаления объекта

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий объектов графических документов ksObject2DNotify/ IObject2DNotify ](ksobject2dnotify.html) > [IObject2DNotify - события ](ksobject2dnotify_events.html) |  Scroll [ [ [ ](ksobject2dnotify_destroyobject.html "К следующему разделу")](ksobject2dnotify_events.html "На уровень выше")](ksobject2dnotify_createobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobject2dnotify.html)

Синтаксис Automation:

VARIANT_BOOL Delete( long objRef );

Синтаксис COM:

BOOL Delete (long objRef);

Входные параметры:

objRef | \- указатель на объект или группу объектов.  
---|---  
  
Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание:

1\. Индекс метода задан в перечислении событий объектов графических документов [ksObject2DNotifyEnum](ksobject2dnotifyenum.html).

2\. Метод используется [при редактировании макроэлементов](redactirovanie_2d.html).

3\. Для обеспечения корректной обработки события удаления вида, нужно учитывать следующее:

– при удалении системного вида собственно сам системный вид не удаляется, удаляются только все объекты в нем;

– номер 0 может иметь служебный вид, создаваемый КОМПАС для режима визуального редактирования макроэлементов, это можно проверить по свойству [IView1::EditMacroVisibleRegime](iview1_editmacrovisibleregime.html).

Подразделы:

(отсутствуют)
