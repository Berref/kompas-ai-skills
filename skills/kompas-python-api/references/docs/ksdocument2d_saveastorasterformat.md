# SaveAsToRasterFormat - Сохранить документ в растровом формате

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_saveastouncompressedrasterformat.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_rasterformatparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksSaveAsToRasterFormat](kssaveastorasterformat.html).

Синтаксис Automation:

BOOL SaveAsToRasterFormat (BSTR fileName,

LPDISPATCH rasterPar);

Входные параметры:

fileName | \- полное имя файла документа,  
---|---  
rasterPar | \- указатель на интерфейс [ksRasterFormatParam](ksrasterformatparam.html), определяющий параметры записи в растровый формат.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

Метод позволяет сохранить присланный документ в растровом формате (BMP, GIF, JPG, PNG, TIF, TGA, PCX, EMF и WMF) с заданными свойствами.

Сохранение в WMF формат не поддерживается. При сохранении в WMF формате файл записывается в формате EMF.

Подразделы:

(отсутствуют)
