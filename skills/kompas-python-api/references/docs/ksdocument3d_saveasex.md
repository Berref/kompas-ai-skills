# SaveAsEx - Сохранить документ с новым именем файла

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_saveastoadditionformat.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_saveas.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL SaveAsEx (BSTR fileName, long saveMode);

Синтаксис COM:

BOOL SaveAsEx (LPOLESTR fileName, long saveMode);

Входные параметры:

fileName | \- новое имя файла документа,  
---|---  
saveMode | \- версия для сохранения: -1 - в предыдущую версию, 0 - в текущую версию, 1 - в версию 5.11.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Если fileName = NULL, то используется имя файла из документа. Если же и в документе отсутствует имя файла, то взводится ошибка.

Подразделы:

(отсутствуют)
