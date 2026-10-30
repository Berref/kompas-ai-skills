# AttachedDocuments - Присоединенные документы

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationObject ](ispecificationobject.html) > [ISpecificationObject - свойства ](ispecificationobject_props.html) |  Scroll [ [ [ ](ispecificationobject_blocknumberbyindex.html "К следующему разделу")](ispecificationobject_props.html "На уровень выше")](ispecificationobject_additionalsection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationobject.html)

Тип данных: указатель на интерфейс [IAttachedDocuments](iattacheddocuments.html) коллекции присоединенных документов

Синтаксис Automation:

AttachedDocuments = iObject.AttachedDocuments | Получить свойство ([* ](1.html))  
---|---  
AttachedDocuments = iObject.GetAttachedDocuments() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_AttachedDocuments (&AttachedDocuments) | Получить свойство  
---|---  
  
Примечание:

1\. Получить коллекцию можно только для базовых и вспомогательных объектов спецификации, если в стиле для заданного раздела установлен признак ручное заполнение или чтение из основной надписи.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
