# ExecuteProcessOfInsertComponentsFromFiles - Запустить процесс вставки компонентов из выбранных файлов

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument3D1 ](ikompasdocument3d1.html) > [IKompasDocument3D1 - методы ](ikompasdocument3d1_methods.html) |  Scroll [ [ [ ](ikompasdocument3d1_findnearestobject.html "К следующему разделу")](ikompasdocument3d1_methods.html "На уровень выше")](ikompasdocument3d1_executeprocessofinsertcomponentfromfile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d1.html)

Синтаксис Automation:

BOOL ExecuteProcessOfInsertComponentsFromFiles( VARIANT FileNames, ProcessTypeEnum ProcessType );

Синтаксис COM:

HRESULT ExecuteProcessOfInsertComponentsFromFiles( VARIANT FileNames, ProcessTypeEnum ProcessType, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

FileNames | \- список файлов,  
---|---  
ProcessType | \- тип процесса из перечисления [ProcessTypeEnum](processtypeenum.html).  
  
Версия Компас v23

Подразделы:

(отсутствуют)
