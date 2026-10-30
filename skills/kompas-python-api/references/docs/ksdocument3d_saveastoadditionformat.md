# SaveAsToAdditionFormat - Сохранить модель в файле формата SAT, XT, STEP, IGES, VRML, STL

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_saveastorasterformat.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_saveasex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL SaveAsToAdditionFormat (BSTR fileName,

LPDISPATCH additionPar);

Синтаксис COM:

BOOL SaveAsToAdditionFormat (LPOLESTR fileName,

LPADDITIONFORMATPARAM additionPar );

Входные параметры:

fileName | \- полное имя файла, в который сохраняется модель,  
---|---  
additionPar | \- указатель на интерфейс [ksAdditionFormatParam](ksadditionformatparam.html) или [IAdditionFormatParam](ksadditionformatparam.html), определяющий параметры записи в дополнительный формат.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
