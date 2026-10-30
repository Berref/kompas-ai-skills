# Objects - Получить массив объектов SAFEARRAY|VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Группы ](bb2344629.html) > [Интерфейс IDrawingGroup ](idrawinggroup.html) > [IDrawingGroup - свойства ](idrawinggroup_props.html) |  Scroll [ [ [ ](idrawinggroup_objectscount.html "К следующему разделу")](idrawinggroup_props.html "На уровень выше")](idrawinggroup_name.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawinggroup.html)

Тип данных: VARIANT типа VT_ARRAY | VT_DISPATCH

Синтаксис Automation:

Objects = Object.Objects | Получить свойство([* ](1.html))  
---|---  
Objects = Object.GetObjects() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Objects( &Objects ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство позволяет получать массив объектов, входящих в группу. Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
