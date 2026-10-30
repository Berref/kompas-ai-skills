# BeginDelete - Начало удаления объекта

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksDrawingObjectNotify/IDrawingObjectNotify ](ksdrawingobjectnotify.html) > [ksDrawingObjectNotify - события ](bo1866135.html) |  Scroll [ [ [ ](ksdrawingobjectnotify_begindestroyobject.html "К следующему разделу")](bo1866135.html "На уровень выше")](ksdrawingobjectnotify_begincopy.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksdrawingobjectnotify.html)

Синтаксис Automation:

BOOL BeginDelete ( VARIANT Obj );

Входные параметры:

iObj | \- VARIANT с типом VT_DISPATCH, если событие генерируется для одного объекта, \- массив SafeArray объектов, если событие генерируется для более чем одного объекта.  
---|---  
  
Возвращаемое значение:

TRUE | \- удалить объект,  
---|---  
FALSE | \- запрещает удаление объекта.  
  
Примечание:

1\. Индекс метода задан в перечислении событий объектов графических документов [ksObject2DNotifyEnum](ksobject2dnotifyenum.html).

2\. Контейнером событий ksDrawingObjectNotify может использоваться объект графического документа [IDrawingObject](idrawingobject.html) и коллекция объектов [IDrawingObjects](idrawingobjects.html).

3\. Для обеспечения корректной обработки события удаления вида, нужно учитывать следующее:

•при удалении системного вида собственно сам системный вид не удаляется: удаляются только все объекты в нем;

•номер 0 может иметь служебный вид, создаваемый КОМПАС для режима визуального редактирования макроэлементов, это можно проверить по свойству [IView1::EditMacroVisibleRegime](iview1_editmacrovisibleregime.html).

Подразделы:

(отсутствуют)
