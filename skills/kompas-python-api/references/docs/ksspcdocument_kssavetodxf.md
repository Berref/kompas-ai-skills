# ksSaveToDXF - Сохранить документ в формате DXF

[API интерфейсов. Версия 5](ag57940.html) > [Документ спецификация (Интерфейс ksSpcDocument) ](ksspcdocument.html) > [ksSpcDocument - методы ](ck1881939.html) |  Scroll [ [ [ ](ksspcdocument_kssetobjparam.html "К следующему разделу")](ck1881939.html "На уровень выше")](ksspcdocument_kssavedocumentex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcdocument.html)

Синтаксис Automation:

BOOL ksSaveToDXF (LPCTSTR DXFFileName);

Входные параметры:

DXFFileName | \- имя файла для записи в формате DXF.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Если FileName = NULL, то используется имя файла из документа. Если же и в документе отсутствует имя файла, то взводится ошибка.

Подразделы:

(отсутствуют)
