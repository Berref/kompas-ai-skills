# AddNode - Добавить узел в дерево

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyTreeNode ](ipropertytreenode.html) > [IPropertyTreeNode - методы](ipropertytreenode_methods.html) |  Scroll [ [ [ ](ipropertytreenode_bringintoview.html "К следующему разделу")](ipropertytreenode_methods.html "На уровень выше")](ipropertytreenode_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertytreenode.html)

Синтаксис Automation:

BOOL AddNode( IPropertyTreeNode * Node, IPropertyTreeNode * After );

Синтаксис COM:

HRESULT AddNode( IPropertyTreeNode * Node, IPropertyTreeNode * After, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Node | \- добавляемый узел [IPropertyTreeNode](ipropertytreenode.html),  
---|---  
After | \- узел, после которого требуется добавить новый [IPropertyTreeNode](ipropertytreenode.html).  
  
Подразделы:

(отсутствуют)
