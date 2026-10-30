# SaveAsToRasterFormat - Конвертировать окно с входящими дочерними окнами

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument1 ](ikompasdocument1.html) > [IKompasDocument1 - методы ](ikompasdocument1_methods.html) |  Scroll [ [ [ ](ikompasdocument1_saveasex.html "К следующему разделу")](ikompasdocument1_methods.html "На уровень выше")](ikompasdocument1_reportpropertiesmultieditmode.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument1.html)

Синтаксис Automation:

BOOL SaveAsToRasterFormat( BSTR FileName, IRasterConvertParameters * Param );

Синтаксис COM:

HRESULT SaveAsToRasterFormat( BSTR FileName, IRasterConvertParameters * Param, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

FileName | \- имя растрового файла,  
---|---  
Param | \- интерфейс параметров конвертации в растровые форматы [IRasterConvertParameters](irasterconvertparameters.html).  
  
Примечание:

Интерфейс [IRasterConvertParameters](irasterconvertparameters.html) требуется получить с помощью метода [IKompasDocument1::GetInterface](ikompasdocument1_getinterface.html), используя константу ksObjectRasterConvertParameters.

Версия Компас v21

Подразделы:

(отсутствуют)
