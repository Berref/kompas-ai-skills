# Align - Выравнивание

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMultiTextLeader ](imultitextleader.html) > [IMultiTextLeader - свойства ](imultitextleader_props.html) |  Scroll [ [ [ ](imultitextleader_arrowtype.html "К следующему разделу")](imultitextleader_props.html "На уровень выше")](imultitextleader_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultitextleader.html)

Тип данных: BOOL

Синтаксис Automation:

VFormat = iObject.VFormat; | Получить свойство ([* ](1.html))  
---|---  
iObject.VFormat = VFormat; | Установить свойство ([* ](1.html))  
VFormat = iObject.GetVFormat( ); | Получить свойство ([**](2.html))  
iObject.SetVFormat( VFormat ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_VFormat( &VFormat ); | Получить свойство  
---|---  
iObject->put_VFormat( VFormat ); | Установить свойство  
  
Значения свойства:

TRUE | \- полки одинаковой длины,  
---|---  
FALSE | \- полки по длине текста.  
  
Примечание:

Свойство позволяет установить и получить выравнивание полок.

Подразделы:

(отсутствуют)
