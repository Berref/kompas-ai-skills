# SaveAsToUncompressedRasterFormat - Сохранить документ в растровом формате без сжатия

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](bt1730611.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_saveastorasterformat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksSaveAsToUncompressedRasterFormat](kssaveastouncompressedrasterformat.html).

Синтаксис Automation:

BOOL SaveAsToUncompressedRasterFormat (BSTR fileName, IDispatch* rasterPar);

Входные параметры:

fileName | \- имя файла документа, должно быть задано полное имя файла,  
---|---  
rasterPar | \- указатель на интерфейс [ksRasterFormatParam](ksrasterformatparam.html), определяющий параметры конвертации в растровый формат.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет сохранить документ в растровом формате без сжатия, с заданными свойствами: цветом, форматом (BMP, GIF, JPG, PNG, TIF, TGA, PCX, EMF и WMF) и т.п. Сохранение в WMF формат не поддерживается. При сохранении в WMF формате файл записывается в формате EMF.

Подробнее см. описание [ksRasterFormatParam](ksrasterformatparam.html).

Подразделы:

(отсутствуют)
