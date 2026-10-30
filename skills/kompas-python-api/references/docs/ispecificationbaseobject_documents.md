# Documents - Документы, связанные с объектом спецификации

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationBaseObject ](ispecificationbaseobject.html) > [ISpecificationBaseObject - свойства ](ispecificationbaseobject_props.html) |  Scroll [ [ [ ](ispecificationbaseobject_draw.html "К следующему разделу")](ispecificationbaseobject_props.html "На уровень выше")](ispecificationbaseobject_commentobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationbaseobject.html)

Тип данных: VARIANT

Синтаксис Automation:

Documents = iObject.Documents | Получить свойство ([* ](1.html))  
---|---  
Documents = iObject.GetDocuments() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Documents( &Documents ) | Получить свойство  
---|---  
  
Примечание:

1\. Связанными документами являются документы, в которых находится геометрия, подключенная к данному объекту, поэтому список связанных с объектом спецификации документов можно получить только для объектов в документе спецификации, в остальных документах геометрию можно подключить только из этого же документа.

2\. Свойство возвращает переменную типа VARIANT на безопасный массив имен файлов, связанных с объектом спецификации SAFEARRAY (VT_ARRAY | VT_BSTR).

3\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
