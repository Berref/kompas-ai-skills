# BeginTextEdit - Событие начала переименования узла дерева

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPropertyTreeNotify\IPropertyTreeNotify](kspropertytreenotify.html) > [ ksPropertyTreeNotify\IPropertyTreeNotify - события](kspropertytreenotify_events.html) |  Scroll [ [ [ ](kspropertytreenotify_expandnode.html "К следующему разделу")](kspropertytreenotify_events.html "На уровень выше")](kspropertytreenotify_collapsenode.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspropertytreenotify.html)

Синтаксис Automation:

BOOL BeginTextEdit( IPropertyTreeNode * Node );

Синтаксис COM:

BOOL BeginTextEdit( IUnknown * Node );

Возвращаемое значение:

TRUE | \- разрешить редактирование,  
---|---  
FALSE | \- запретить редактирование.  
  
Выходные параметры:

Node | \- указатель на интерфейс узла [IPropertyTreeNode](ipropertytreenode.html).  
---|---  
  
Подразделы:

(отсутствуют)
