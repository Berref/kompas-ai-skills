# InsertionDefinition - Получить описание по имени или индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вставки видов, фрагментов, OLE объектов ](bb2331024.html) > [Интерфейс IInsertionsManager ](iinsertionsmanager.html) > [IInsertionsManager - свойства ](iinsertionsmanager_props.html) |  Scroll [ [ [ ](iinsertionsmanager_insertiondefinitions.html "К следующему разделу")](iinsertionsmanager_props.html "На уровень выше")](iinsertionsmanager_definitionscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinsertionsmanager.html)

Тип данных: указатель на интерфейс [IInsertionDefinition](iinsertiondefinition.html)

Синтаксис Automation:

InsertionDefinition = Object.InsertionDefinition( long type, VARIANT Index ) | Получить свойство ([* ](1.html))  
---|---  
InsertionDefinition = Object.GetInsertionDefinition( long type, VARIANT Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_InsertionDefinition( ksInsertionTypeEnum type, VARIANT Index, &InsertionDefinition ) | Получить свойство  
---|---  
  
Входные параметры:

type | \- тип вставки фрагмента или вида,  
---|---  
Index | \- индекс или имя вставки фрагмента или вида.  
  
Примечание:

1\. Свойство позволяет получать описание вставки фрагмента или вида по имени или индексу.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
