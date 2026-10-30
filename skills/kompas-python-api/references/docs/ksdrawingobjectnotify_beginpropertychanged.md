# BeginPropertyChanged - Начало изменения свойств объекта

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksDrawingObjectNotify/IDrawingObjectNotify ](ksdrawingobjectnotify.html) > [ksDrawingObjectNotify - события ](bo1866135.html) |  Scroll [ [ [ ](ksdrawingobjectnotify_beginrotate.html "К следующему разделу")](bo1866135.html "На уровень выше")](ksdrawingobjectnotify_beginprocess.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksdrawingobjectnotify.html)

Синтаксис:

BOOL BeginPropertyChanged( VARIANT Objects );

Входной параметр:

Objects | \- указатель на объект VT_DISPATCH и/или массив объектов VT_ARRAY | VT_DISPATCH.  
---|---  
  
Возвращаемое значение:

TRUE | \- Разрешить изменение свойств объекта,  
---|---  
FALSE | \- Запретить изменение свойств объекта.  
  
Подразделы:

(отсутствуют)
