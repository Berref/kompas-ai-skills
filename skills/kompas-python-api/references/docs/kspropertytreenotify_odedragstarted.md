# NodeDragStarted - Событие начала перемещения узла дерева

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPropertyTreeNotify\IPropertyTreeNotify](kspropertytreenotify.html) > [ ksPropertyTreeNotify\IPropertyTreeNotify - события](kspropertytreenotify_events.html) |  Scroll [ [ [ ](kspropertytreenotify_selectnodes.html "К следующему разделу")](kspropertytreenotify_events.html "На уровень выше")](kspropertytreenotify_nodedragover.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspropertytreenotify.html)

Синтаксис Automation:

BOOL NodeDragStarted( IPropertyTreeNode* Node );

Синтаксис COM:

BOOL NodeDragStarted( IUnknown * Node );

Возвращаемое значение:

TRUE | \- разрешить перемещение.  
---|---  
  
Выходные параметры:

Node | \- указатель на интерфейс узла [IPropertyTreeNode](ipropertytreenode.html).  
---|---  
  
Примечание:

Для использования перемещения в дереве требуется установить свойство [IPropertyTree::EnableDrag](ipropertytree_enabledrag.html).

В событии также требуется разрешить перемещение узла, установив свойство [IPropertyTreeNode::DragPermitted](ipropertytreenode_dragpermitted.html) равным true.

В событии нужно учитывать, что перетаскиваться могут несколько селектированных в данный момент узлов. В зависимости от этого библиотека может запрещать или разрешать перемещение.

Подразделы:

(отсутствуют)
