# Item - Узел, заданный по индексу или тексту марки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMarkNodes ](imarknodes.html) > [IMarkNodes - свойства ](imarknodes_props.html) |  Scroll [ [ [ ](imarknodes_methods.html "К следующему разделу")](imarknodes_props.html "На уровень выше")](imarknodes_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarknodes.html)

Тип данных: указатель на интерфейс узла [IMarkNode](imarknode.html)

Синтаксис Automation:

Item = iObject.Item(Index) | Получить свойство([* ](1.html))  
---|---  
Item = iObject.GetItem(Index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Item = iObject->get_Item(Index) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс узла в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс узла, \- VT_BSTR - имя узла.  
---|---  
  
Описание:

Индекс равный 0 позволяет получить указатель на узел, являющийся маркой оси.

Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
