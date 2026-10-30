# ShelfDirection - Направление полки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMultiTextLeader ](imultitextleader.html) > [IMultiTextLeader - свойства ](imultitextleader_props.html) |  Scroll [ [ [ ](imultitextleader_textdirection.html "К следующему разделу")](imultitextleader_props.html "На уровень выше")](imultitextleader_shelfy.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultitextleader.html)

Тип данных: из перечисления [ksShelfDirectionEnum](ksshelfdirectionenum.html)

Синтаксис Automation:

ShelfDirection = iObject.ShelfDirection | Получить свойство ([* ](1.html))  
---|---  
iObject.ShelfDirection = ShelfDirection | Установить свойство ([* ](1.html))  
ShelfDirection = iObject.GetShelfDirection( ) | Получить свойство ([**](2.html))  
iObject.SetShelfDirection( ShelfDirection ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ShelfDirection( &ShelfDirection ) | Получить свойство  
---|---  
iObject->put_ShelfDirection( ShelfDirection ) | Установить свойство  
  
Значения свойства:

ksLSLeft | -1 | \- влево,  
---|---|---  
ksLSRight | 1 | \- вправо.  
  
Примечание:

Свойство позволяет установить и получить направление полки.

Подразделы:

(отсутствуют)
