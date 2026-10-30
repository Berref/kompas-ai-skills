# ReadOnly - Запретить изменение текста в ячейке

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Таблица ](bb3106514.html) > [Интерфейс ICellFormat ](icellformat.html) > [ICellFormat - свойства ](icellformat_props.html) |  Scroll [ [ [ ](icellformat_rightedge.html "К следующему разделу")](icellformat_props.html "На уровень выше")](icellformat_oneline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icellformat.html)

Тип данных: BOOL

Синтаксис Automation:

ReadOnly = Object.ReadOnly | Получить свойство([* ](1.html))  
---|---  
Object.ReadOnly = ReadOnly | Установить свойство ([* ](1.html))  
ReadOnly = Object.GetReadOnly( ) | Получить свойство ([**](2.html))  
Object.SetReadOnly( ReadOnly ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ReadOnly( &ReadOnly ) | Получить свойство  
---|---  
Object.put_ReadOnly( ReadOnly ) | Установить свойство  
  
Примечание:

1\. Свойство позволяет устанавливать и получать признак запрета на изменение текста в ячейке.

2\. Для того, чтобы сузить текст в ячейке таблицы необходимо:

•снять признак запрета на редактирование ячейки и изменить текст,

•вызвать метод [IDrawingObject::Update,](idrawingobject_update.html)

•установить признак запрета на редактирование ячейки,

•вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
