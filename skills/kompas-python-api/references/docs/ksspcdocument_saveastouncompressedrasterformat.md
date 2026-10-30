# SaveAsToUncompressedRasterFormat - Сохранить документ в растровый формат без сжатия

[API интерфейсов. Версия 5](ag57940.html) > [Документ спецификация (Интерфейс ksSpcDocument) ](ksspcdocument.html) > [ksSpcDocument - методы ](ck1881939.html) |  Scroll [ [ [ ](ck1718054.html "К следующему разделу")](ck1881939.html "На уровень выше")](ksspcdocument_saveastorasterformat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspcdocument.html)

Аналог данного метода при использовании API экспортных функций - [ksSaveAsToUncompressedRasterFormat](kssaveastouncompressedrasterformat.html).

Синтаксис Automation:

BOOL SaveAsToUncompressedRasterFormat(BSTR fileName, IDispatch* rasterPar);

Входные параметры:

fileName | \- полное имя файла документа,  
---|---  
rasterPar | \- указатель на интерфейс [ksRasterFormatParam](ksrasterformatparam.html), определяющий параметры записи в растровый формат.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечание:

Метод позволяет сохранить документ спецификации в растровом формате без сжатия, с заданными свойствами: цветом, форматом (BMP, GIF, JPG, PNG, TIF, TGA, PCX, EMF и WMF) и т.п. Сохранение в WMF формат не поддерживается. При сохранении в WMF формате файл записывается в формате EMF.

Подробнее см. описание [ksRasterFormatParam](ksrasterformatparam.html).

Подразделы:

(отсутствуют)
