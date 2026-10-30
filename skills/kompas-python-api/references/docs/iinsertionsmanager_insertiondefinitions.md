# InsertionDefinitions - Описания фрагментов и видов

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вставки видов, фрагментов, OLE объектов ](bb2331024.html) > [Интерфейс IInsertionsManager ](iinsertionsmanager.html) > [IInsertionsManager - свойства ](iinsertionsmanager_props.html) |  Scroll [ [ [ ](iinsertionsmanager_methods.html "К следующему разделу")](iinsertionsmanager_props.html "На уровень выше")](iinsertionsmanager_insertiondefinition.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinsertionsmanager.html)

Тип данных: VARIANT типа VT_ARRAY | VT_DISPATCH

Синтаксис Automation:

InsertionDefinitions = Object.InsertionDefinitions | Получить свойство ([* ](1.html))  
---|---  
InsertionDefinitions = Object.GetInsertionDefinitions() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_InsertionDefinitions( &InsertionDefinitions ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство позволяет получать массив описаний фрагментов и видов. Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
