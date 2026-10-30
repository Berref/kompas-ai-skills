# VFormat - Признак вертикального форматирования

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Интерфейс IDrawingText ](idrawingtext.html) > [IDrawingText - свойства ](idrawingtext_props.html) |  Scroll [ [ [ ](idrawingtext_width.html "К следующему разделу")](idrawingtext_props.html "На уровень выше")](idrawingtext_mirrorsymmetry.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingtext.html)

Тип данных: BOOL

Синтаксис Automation:

VFormat = iObject.VFormat; | Получить свойство([* ](1.html))  
---|---  
iObject.VFormat = VFormat; | Установить свойство ([* ](1.html))  
VFormat = iObject.GetVFormat(); | Получить свойство ([**](2.html))  
iObject.SetVFormat(VFormat); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_VFormat(&VFormat); | Получить свойство  
---|---  
iObject->put_VFormat(VFormat); | Установить свойство  
  
Значения свойства:

TRUE | \- изменение шага строк,  
---|---  
FALSE | \- нет форматирования.  
  
Примечание:

Свойство позволяет установить и получить признак вертикального форматирования.

Подразделы:

(отсутствуют)
