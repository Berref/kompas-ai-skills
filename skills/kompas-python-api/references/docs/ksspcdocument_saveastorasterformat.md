# SaveAsToRasterFormat - Сохранить документ в растровом формате

[API интерфейсов. Версия 5](ag57940.html) > [Документ спецификация (Интерфейс ksSpcDocument) ](ksspcdocument.html) > [ksSpcDocument - методы ](ck1881939.html) |  Scroll [ [ [ ](ksspcdocument_saveastouncompressedrasterformat.html "К следующему разделу")](ck1881939.html "На уровень выше")](ksspcdocument_rasterformatparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcdocument.html)

Аналог данного метода при использовании API экспортных функций - [ksSaveAsToRasterFormat](kssaveastorasterformat.html).

Синтаксис Automation:

BOOL SaveAsToRasterFormat (BSTR fileName,

LPDISPATCH rasterPar);

Входные параметры:

fileName | \- полное имя файла документа,  
---|---  
rasterPar | \- указатель на интерфейс [ksRasterFormatParam](ksrasterformatparam.html), определяющий параметры записи в растровый формат.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечание:

Метод позволяет сохранить присланный документ в растровом формате (BMP, GIF, JPG, PNG, TIF, TGA, PCX, EMF и WMF) с заданными свойствами.

Сохранение в WMF формат не поддерживается. При сохранении в WMF формате файл записывается в формате EMF.

Подразделы:

(отсутствуют)
