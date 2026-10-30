# NodeDragDroped - Событие перемещения узла дерева

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPropertyTreeNotify\IPropertyTreeNotify](kspropertytreenotify.html) > [ ksPropertyTreeNotify\IPropertyTreeNotify - события](kspropertytreenotify_events.html) |  Scroll [ [ [ ](kspropertytreenotify_nodedragover.html "К следующему разделу")](kspropertytreenotify_events.html "На уровень выше")](kspropertytreenotify_nodedblclick.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspropertytreenotify.html)

Синтаксис Automation:

BOOL NodeDragDroped( IPropertyTreeNode* Node, IPropertyTreeNode* DragNode, BOOL CtrlPressed );

Синтаксис COM:

BOOL NodeDragDroped( IUnknown * Node, IUnknown * DragNode, BOOL CtrlPressed, BOOL * Result );

Возвращаемое значение:

| \- не используется.  
---|---  
  
Выходные параметры:

Node | \- перемещаемый узел [IPropertyTreeNode](ipropertytreenode.html),  
---|---  
DragNode | \- узел, к которому перемещается [IPropertyTreeNode](ipropertytreenode.html),  
CtrlPressed | \- признак нажатия клавиши Ctrl.  
  
Подразделы:

(отсутствуют)
