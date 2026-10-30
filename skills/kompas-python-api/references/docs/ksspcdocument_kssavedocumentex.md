# ksSaveDocumentEx - Сохранить документ с новым именем файла

[API интерфейсов. Версия 5](ag57940.html) > [Документ спецификация (Интерфейс ksSpcDocument) ](ksspcdocument.html) > [ksSpcDocument - методы ](ck1881939.html) |  Scroll [ [ [ ](ksspcdocument_kssavetodxf.html "К следующему разделу")](ck1881939.html "На уровень выше")](ksspcdocument_kssavedocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcdocument.html)

Синтаксис Automation:

BOOL ksSaveDocumentEx( BSTR FileName, long SaveMode );

Синтаксис COM:

BOOL ksSaveDocumentEx( LPOLESTR FileName, long SaveMode );

Входные параметры:

FileName | \- новое имя файла документа,  
---|---  
SaveMode | \- версия для сохранения: -1 - в предыдущую версию, 0 - в текущую версию, 1 - в версию 5.11.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Если FileName = NULL, то используется имя файла из документа. Если же и в документе отсутствует имя файла, то взводится ошибка.

Подразделы:

(отсутствуют)
