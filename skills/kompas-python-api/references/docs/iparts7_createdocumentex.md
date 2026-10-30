# CreateDocumentEx - Создать локальную деталь и добавить в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IParts7 ](iparts7.html) > [IParts7 - методы ](iparts7_methods.html) |  Scroll [ [ [ ](iparts7_createsubassembly.html "К следующему разделу")](iparts7_methods.html "На уровень выше")](iparts7_createdocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparts7.html)

Синтаксис Automation:

LPDISPATCH CreateDocumentEx( BSTR StartFileName, DocumentTypeEnum Type, BOOL Local, BOOL Redraw );

Синтаксис COM:

HRESULT CreateDocumentEx( BSTR StartFileName, DocumentTypeEnum Type, BOOL Local, BOOL Redraw, IPart7 * * Result );

Возвращаемое значение:

  
| \- указатель на интерфейс вставки [IPart7](ipart7.html).  
---|---  
  
Входные параметры:

StartFileName | \- имя файла по умолчанию,  
---|---  
Type | \- тип документа вставки,  
Local | \- признак локальной детали,  
Redraw | \- TRUE для обновления окна документа.  
  
Подразделы:

(отсутствуют)
