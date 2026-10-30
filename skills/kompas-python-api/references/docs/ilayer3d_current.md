# Current - Состояние слоя - текущий

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Слои ](cu1735361.html) > [Интерфейс ILayer3D ](ilayer3d.html) > [ILayer3D - свойства ](ilayer3d_props.html) |  Scroll [ [ [ ](ilayer3d_editable.html "К следующему разделу")](ilayer3d_props.html "На уровень выше")](ilayer3d_comment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayer3d.html)

Тип данных: BOOL

Синтаксис Automation:

Current = Object.Current | Получить свойство ([* ](1.html))  
---|---  
Object.Current = Current | Установить свойство ([* ](1.html))  
Current = Object.GetCurrent() | Получить свойство ([**](2.html))  
Object.SetCurrent (Current) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Current( &Current ) | Получить свойство  
---|---  
Object.put_Current( Current ) | Установить свойство  
  
Примечание:

Установить свойство можно только равным TRUE. Новый слой всегда создается текущим.

Подразделы:

(отсутствуют)
