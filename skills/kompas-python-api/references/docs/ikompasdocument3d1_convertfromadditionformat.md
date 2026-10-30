# ConvertFromAdditionFormat - Конвертация документов из дополнительных форматов

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument3D1 ](ikompasdocument3d1.html) > [IKompasDocument3D1 - методы ](ikompasdocument3d1_methods.html) |  Scroll [ [ [ ](ikompasdocument3d1_converttoadditionformat.html "К следующему разделу")](ikompasdocument3d1_methods.html "На уровень выше")](ikompasdocument3d1_clearundo.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d1.html)

Синтаксис Automation:

BOOL ConvertFromAdditionFormat( BSTR FileName, IAdditionConvertParameters * Param );

Синтаксис COM:

HRESULT ConvertFromAdditionFormat( BSTR FileName, IAdditionConvertParameters * Param, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

FileName | \- имя файла,  
---|---  
Param | \- Параметры конвертации [IAdditionConvertParameters](iadditionconvertparameters.html).  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
