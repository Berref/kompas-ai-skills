# SaveAsToUncompressedRasterFormat - Сохранить документ в растровый формат без сжатия

[API интерфейсов. Версия 5](ag57940.html) > [Текстовый документ (Интерфейс ksDocumentTxt) ](ksdocumenttxt.html) > [ksDocumentTxt - методы ](ksdocumenttxt_methods.html) |  Scroll [ [ [ ](ck1888293.html "К следующему разделу")](ksdocumenttxt_methods.html "На уровень выше")](ksdocumenttxt_saveastorasterformat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumenttxt.html)

Аналог данного метода при использовании API экспортных функций - [ksSaveAsToUncompressedRasterFormat](kssaveastouncompressedrasterformat.html).

Синтаксис Automation:

BOOL SaveAsToUncompressedRasterFormat (BSTR fileName, LPDISPATCH rasterPar);

Входные параметры:

fileName | \- полное имя файла документа,  
---|---  
rasterPar | \- Указатель на интерфейс [ksRasterFormatParam](ksrasterformatparam.html), определяющий параметры записи в растровый формат.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

Метод позволяет сохранить присланный документ в растровом формате (BMP, GIF, JPG, PNG, TIF, TGA, PCX, EMF и WMF) с заданными свойствами.

Сохранение в WMF формат не поддерживается. При сохранении в WMF формате файл записывается в формате EMF.

Подразделы:

(отсутствуют)
