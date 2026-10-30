# SaveAsEx - Сохранить документ под другим именем

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument1 ](ikompasdocument1.html) > [IKompasDocument1 - методы ](ikompasdocument1_methods.html) |  Scroll [ [ [ ](ikompasdocument1_setchanged.html "К следующему разделу")](ikompasdocument1_methods.html "На уровень выше")](ikompasdocument1_saveastorasterformat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument1.html)

Синтаксис Automation:

BOOL SaveAsEx( BSTR PathName, long saveMode );

Синтаксис COM:

HRESULT SaveAsEx( BSTR PathName, long saveMode, BOOL * Result );

Входные параметры:

PathName | \- новое имя файла документа,  
---|---  
saveMode | \- версия для сохранения.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
