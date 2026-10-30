# SaveAsToUncompressedRasterFormat - Cохранить документ в растровый формат

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_setactive.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_saveastorasterformat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL SaveAsToUncompressedRasterFormat (BSTR fileName, LPDISPATCH rasterPar);

Синтаксис COM:

BOOL SaveAsToUncompressedRasterFormat (LPOLESTR fileName, LPRASTERFORMATPARAM rasterPar );

Выходные параметры:

fileName | \- Имя файла документа. Задается полное имя файла,  
---|---  
rasterPar | \- Указатель на интерфейс [ksRasterFormatParam](ksrasterformatparam.html) или [IRasterFormatParam](ksrasterformatparam.html), определяющий параметры конвертации в растровый формат.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

Метод позволяет сохранить документ в растровый формат (BMP, GIF, JPG, PNG, TIF, TGA, PCX, EMF и WMF) без сжатия, с заданными свойствами.

Сохранение в WMF формат не поддерживается. При сохранении в WMF формате файл записывается в формате EMF.

Подробнее см. описание интерфейса [ksRasterFormatParam](ksrasterformatparam.html). Для API экспортных функций - метод [ksSaveAsToUncompressedRasterFormat](ksdocument3d_saveastouncompressedrasterformat.html).

Подразделы:

(отсутствуют)
