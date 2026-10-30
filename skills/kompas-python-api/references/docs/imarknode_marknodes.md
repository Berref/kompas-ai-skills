# MarkNodes - Коллекция узлов марок

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMarkNode ](imarknode.html) > [IMarkNode - свойства ](imarknode_props.html) |  Scroll [ [ [ ](imarknode_marktype.html "К следующему разделу")](imarknode_props.html "На уровень выше")](imarknode_doublemark.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarknode.html)

Тип данных: указатель на интерфейс [IMarkNodes](imarknodes.html)

Синтаксис Automation:

MarkNodes = iObject.MarkNodes( Left ) | Получить свойство([* ](1.html))  
---|---  
MarkNodes = iObject.GetMarkNodes( Left ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_MarkNodes(Left, &MarkNodes) | Получить свойство  
---|---  
  
Входные параметры:

Left (BOOL) | TRUE - возвращается коллекция узлов слева по направлению оси, FALSE - справа.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
