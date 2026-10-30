# GetExternalFilesNamesEx - Получить список внешних файлов в виде SAFEARRAY BSTR - (VT_ARRAY | VT_BSTR) и их типов в виде SAFEARRAY long - (VT_ARRAY | VT_I4)

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument1 ](ikompasdocument1.html) > [IKompasDocument1 - методы ](ikompasdocument1_methods.html) |  Scroll [ [ [ ](ikompasdocument1_getinterface.html "К следующему разделу")](ikompasdocument1_methods.html "На уровень выше")](ikompasdocument1_getdocumentgabarit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument1.html)

Синтаксис Automation:

BOOL GetExternalFilesNamesEx( BOOL allFiles, VARIANT * Files, VARIANT * FilesTypes );

Синтаксис COM:

BOOL GetExternalFilesNamesEx( BOOL allFiles, VARIANT * Files, VARIANT * FilesTypes );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

allFiles | \- TRUE - рекурсивно по всем файлам,  
---|---  
| \- FALSE - только по внешнему уровню.  
  
Выходные параметры:

Files | \- массив VT_ARRAY | VT_BSTR имен файлов,  
---|---  
FilesTypes | \- массив VT_ARRAY | VT_I4 типов файлов (из перечисления [ksExternalFilesTypesEnum](ksexternalfilestypesenum.html)).  
  
Подразделы:

(отсутствуют)
