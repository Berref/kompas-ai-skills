# DefinitionsCount - Количество описаний

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вставки видов, фрагментов, OLE объектов ](bb2331024.html) > [Интерфейс IInsertionsManager ](iinsertionsmanager.html) > [IInsertionsManager - свойства ](iinsertionsmanager_props.html) |  Scroll [ [ [ ](iinsertionsmanager_insertiondefinition.html "К следующему разделу")](iinsertionsmanager_props.html "На уровень выше")](iinsertionsmanager_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinsertionsmanager.html)

Тип данных: long

Синтаксис Automation:

DefinitionsCount = Object.DefinitionsCount( long type ) | Получить свойство ([* ](1.html))  
---|---  
DefinitionsCount = Object.GetDefinitionsCount( long type ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_DefinitionsCount( ksInsertionTypeEnum type, &DefinitionsCount ) | Получить свойство  
---|---  
  
Входные параметры:

type | \- тип вставки фрагмента или вида.  
---|---  
  
Примечание:

1\. Свойство позволяет получать количество описаний вставок фрагмента или вида заданного типа.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
