# multiPageOutput - Признак сохранения всех листов в одном файле

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Параметры сохранения растра (Интерфейсы ksRasterFormatParam, IRasterFormatParam) ](ksrasterformatparam.html) > [IRasterFormatParam - свойства ](ksrasterformatparam_props.html) |  Scroll [ [ [ ](ksrasterformatparam_onlythinline.html "К следующему разделу")](ksrasterformatparam_props.html "На уровень выше")](ksrasterformatparam_greyscale.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrasterformatparam.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- сохранять все листы в одном файле,  
---|---  
FALSE | \- сохранять листы в отдельных файлах.  
  
Синтаксис Automation:

multiPageOutput = iRasterFormatParam.multiPageOutput | Получить свойство([* ](1.html))  
---|---  
iRasterFormatParam.multiPageOutput = multiPageOutput | Установить свойство ([* ](1.html))  
multiPageOutput = iRasterFormatParam.GetMultiPageOutput() | Получить свойство ([**](2.html))  
iRasterFormatParam.SetMultiPageOutput(multiPageOutput) | Установить свойство ([**](2.html))  
  
Примечание:

Свойство используется только для формата TIFF.

Подразделы:

(отсутствуют)
