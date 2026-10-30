# rangeIndex - Признак выбора стороны страниц

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Параметры сохранения растра (Интерфейсы ksRasterFormatParam, IRasterFormatParam) ](ksrasterformatparam.html) > [IRasterFormatParam - свойства ](ksrasterformatparam_props.html) |  Scroll [ [ [ ](ksrasterformatparam_returnresultasarraybytes.html "К следующему разделу")](ksrasterformatparam_props.html "На уровень выше")](ksrasterformatparam_pages.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrasterformatparam.html)

Тип данных: short

Значения свойства:

0 | \- все страницы,  
---|---  
1 | \- нечетные страницы,  
2 | \- четные страницы.  
  
Синтаксис Automation:

rangeIndex = iRasterFormatParam.rangeIndex | Получить свойство([* ](1.html))  
---|---  
iRasterFormatParam.rangeIndex = rangeIndex | Установить свойство ([* ](1.html))  
rangeIndex = iRasterFormatParam.GetRangeIndex() | Получить свойство ([**](2.html))  
iRasterFormatParam.SetRangeIndex(rangeIndex) | Установить свойство ([**](2.html))  
  
Примечание:

Свойство используется для многолистовых документов (текстовых документов и спецификаций).

Подразделы:

(отсутствуют)
