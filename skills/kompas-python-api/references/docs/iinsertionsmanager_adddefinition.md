# AddDefinition - Создать новое описание для фрагмента или вида

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вставки видов, фрагментов, OLE объектов ](bb2331024.html) > [Интерфейс IInsertionsManager ](iinsertionsmanager.html) > [IInsertionsManager - методы ](iinsertionsmanager_methods.html) |  Scroll [ [ [ ](iinsertionobjects.html "К следующему разделу")](iinsertionsmanager_methods.html "На уровень выше")](iinsertionsmanager_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinsertionsmanager.html)

Синтаксис Automation:

LPDISPATCH AddDefinition( long type,

BSTR Name,

BSTR FileName );

Синтаксис COM:

HRESULT AddDefinition( ksInsertionTypeEnum type,

BSTR Name,

BSTR FileName,

IInsertionDefinition ** Result );

Входные параметры:

type | \- тип вставки фрагмента или вида,  
---|---  
Name | \- имя вставки,  
FileName | \- имя файла, из которого производится вставка.  
  
Возвращаемое значение:

| \- Указатель на интерфейс вставки фрагмента или вида [IInsertionDefinition](iinsertiondefinition.html).  
---|---  
  
Примечание:

Метод позволяет создать новое описание вставки фрагмента или вида.

Подразделы:

(отсутствуют)
