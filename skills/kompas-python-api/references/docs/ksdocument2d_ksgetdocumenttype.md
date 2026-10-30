# ksGetDocumentType - Получить тип документа

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Работа с документом ](bt1730260.html) |  Scroll [ [ [ ](ksdocument2d_ksrebuilddocument.html "К следующему разделу")](bt1730260.html "На уровень выше")](bt1730260.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksGetDocumentType](ksgetdocumenttype.html).

Синтаксис Automation:

long ksGetDocumentType (long doc);

Входные параметры:

doc | \- указатель на документ,  
---|---  
  
Возвращаемое значение:

тип документа | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
[Типы документов](doctype.html)

Примечание:

Если указатель doc = 0, возвращается тип активного документа.

Подразделы:

(отсутствуют)
