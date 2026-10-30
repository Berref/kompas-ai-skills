# SaveAsToRasterFormat - Сохранить документ в растровом файле

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_saveastouncompressedrasterformat.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_saveastoadditionformat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL SaveAsToRasterFormat (BSTR fileName,

LPDISPATCH rasterPar);

Синтаксис COM:

BOOL SaveAsToRasterFormat (LPOLESTR fileName,

LPRASTERFORMATPARAM rasterPar );

Входные параметры:

fileName | \- полное имя файла, в который сохраняется модель,  
---|---  
rasterPar | \- указатель на интерфейс [ksRasterFormatParam](ksrasterformatparam.html) или [IRasterFormatParam](ksrasterformatparam.html), определяющий параметры записи в растровый формат.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

Метод позволяет сохранить присланный документ в растровом формате (BMP, GIF, JPG, PNG, TIF, TGA, PCX, EMF и WMF) с заданными свойствами.

Сохранение в WMF формат не поддерживается. При сохранении в WMF формате файл записывается в формате EMF.

Подразделы:

(отсутствуют)
