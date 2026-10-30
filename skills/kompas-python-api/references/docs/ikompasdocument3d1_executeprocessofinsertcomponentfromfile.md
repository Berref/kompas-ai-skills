# ExecuteProcessOfInsertComponentFromFile - Запустить процесс вставки компонента из файла или библиотеки моделей

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument3D1 ](ikompasdocument3d1.html) > [IKompasDocument3D1 - методы ](ikompasdocument3d1_methods.html) |  Scroll [ [ [ ](ikompasdocument3d1_executeprocessofinsertcomponentsfromfiles.html "К следующему разделу")](ikompasdocument3d1_methods.html "На уровень выше")](ikompasdocument3d1_excludeobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d1.html)

Синтаксис Automation:

BOOL ExecuteProcessOfInsertComponentFromFile( BSTR FileName, ProcessTypeEnum ProcessType );

Синтаксис COM:

HRESULT ExecuteProcessOfInsertComponentFromFile( BSTR FileName, ProcessTypeEnum ProcessType, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

FileName | \- имя файла,  
---|---  
ProcessType | \- тип процесса,  
prAddPartFromFile | \- добавить компонент из файла,  
prAddLocalPartFromFile | \- добавить локальную деталь из файла,  
prAddLayoutGeometryFromFile | \- добавить компоновочную геометрию,  
prAddBilletPartFromFile | \- добавить деталь-заготовку.  
  
Подразделы:

(отсутствуют)
