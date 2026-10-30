# MoveNodes - Переместить узлы

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyTreeNode ](ipropertytreenode.html) > [IPropertyTreeNode - методы](ipropertytreenode_methods.html) |  Scroll [ [ [ ](ipropertytreenode_setnodeicon.html "К следующему разделу")](ipropertytreenode_methods.html "На уровень выше")](ipropertytreenode_hideheader.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertytreenode.html)

Синтаксис Automation:

BOOL MoveNodes( VARIANT Nodes, IPropertyTreeNode * After );

Синтаксис COM:

HRESULT MoveNodes( VARIANT Nodes, IPropertyTreeNode * After, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Nodes | \- список узлов,  
---|---  
Afters | \- узел [IPropertyTreeNode](ipropertytreenode.html), после которого требуется добавить перемещаемые узлы.  
  
Подразделы:

(отсутствуют)
