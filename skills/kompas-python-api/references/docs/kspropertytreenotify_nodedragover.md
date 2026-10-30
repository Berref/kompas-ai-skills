# NodeDragOver - Событие перемещения узла дерева

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPropertyTreeNotify\IPropertyTreeNotify](kspropertytreenotify.html) > [ ksPropertyTreeNotify\IPropertyTreeNotify - события](kspropertytreenotify_events.html) |  Scroll [ [ [ ](kspropertytreenotify_odedragstarted.html "К следующему разделу")](kspropertytreenotify_events.html "На уровень выше")](kspropertytreenotify_nodedragdroped.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspropertytreenotify.html)

Синтаксис Automation:

BOOL NodeDragOver( IPropertyTreeNode* Node, IPropertyTreeNode* DragNode, BOOL CtrlPressed, BOOL RequiredDropAfter );

Синтаксис COM:

BOOL NodeDragOver( IUnknown * Node, IUnknown * DragNode, BOOL CtrlPressed, BOOL RequiredDropAfter );

Возвращаемое значение:

TRUE | \- разрешить перемещение.  
---|---  
  
Выходные параметры:

Node | \- перемещаемый узел [IPropertyTreeNode](ipropertytreenode.html),  
---|---  
DragNode  | \- узел, к которому перемещается [IPropertyTreeNode](ipropertytreenode.html),  
CtrlPressed | \- признак нажатия клавиши Ctrl,  
RequiredDropAfter |  -TRUE - узел будет вставляться после узла DragNode, \- FALSE - узел будет вставляться внутрь узла DragNode.  
  
Примечание:

Для использования перемещения в дереве требуется установить свойство [IPropertyTree::EnableDrag](ipropertytree_enabledrag.html).

В событии [ksPropertyTreeNotify::NodeDragStarted](kspropertytreenotify_odedragstarted.html) также требуется разрешить перемещение узла, установив свойство [IPropertyTreeNode::DragPermitted](ipropertytreenode_dragpermitted.html) равным true.

В событии нужно учитывать, что перетаскиваться могут несколько селектированных в данный момент узлов. В зависимости от этого библиотека может запрещать или разрешать перемещение.

В зависимости от данных признаков в событии требуется установить свойству [IPropertyTreeNode::DropPermission](ipropertytreenode_droppermission.html) нужное значение.

Подразделы:

(отсутствуют)
