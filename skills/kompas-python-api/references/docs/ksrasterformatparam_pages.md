# pages - Список диапазонов выводимых страниц

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Параметры сохранения растра (Интерфейсы ksRasterFormatParam, IRasterFormatParam) ](ksrasterformatparam.html) > [IRasterFormatParam - свойства ](ksrasterformatparam_props.html) |  Scroll [ [ [ ](ksrasterformatparam_rangeindex.html "К следующему разделу")](ksrasterformatparam_props.html "На уровень выше")](ksrasterformatparam_onlythinline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrasterformatparam.html)

Тип данных: строка

Значения свойства:

Формат списка - "beg1-end1, beg2-end2, beg3-end3, ...",

где begN - начало N-го интервала, endN - конец N-го интервала.

Например, "1-18, 24-25".

Синтаксис Automation:

pages = iRasterFormatParam.pages | Получить свойство([* ](1.html))  
---|---  
iRasterFormatParam.pages = pages | Установить свойство ([* ](1.html))  
pages = iRasterFormatParam.GetPages() | Получить свойство ([**](2.html))  
iRasterFormatParam.SetPages(pages) | Установить свойство ([**](2.html))  
  
Примечание:

1\. Свойство используется для многолистовых документов (текстовых документов и спецификаций).

2\. Если строка пуста, свойство не используется.

Подразделы:

(отсутствуют)
