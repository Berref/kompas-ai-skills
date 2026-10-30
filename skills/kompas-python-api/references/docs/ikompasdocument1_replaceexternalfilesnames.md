# ReplaceExternalFilesNames - Изменить ссылки на файл в документе

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument1 ](ikompasdocument1.html) > [IKompasDocument1 - методы ](ikompasdocument1_methods.html) |  Scroll [ [ [ ](ikompasdocument1_reportpropertiesmultieditmode.html "К следующему разделу")](ikompasdocument1_methods.html "На уровень выше")](ikompasdocument1_redrawdocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument1.html)

Синтаксис Automation:

BOOL ReplaceExternalFilesNames( BOOL allFiles, BSTR OldFileName, BSTR NewFileName );

Синтаксис COM

HRESULT ReplaceExternalFilesNames( BOOL allFiles, BSTR OldFileName, BSTR NewFileName, BOOL * Result );

Возвращаемое значение:

TRUE | \- есть локальный результат,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

allFiles | \- TRUE - рекурсивно по всем файлам, \- FALSE - только по внешнему уровню,  
---|---  
OldFileName | \- старое имя файла,  
NewFileName | \- тип интерфейса из перечисления [KompasAPIObjectTypeEnum](kompasapiobjecttypeenum.html).  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
