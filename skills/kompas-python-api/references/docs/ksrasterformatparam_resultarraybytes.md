# resultArrayBytes - Результат сохранения в растр в виде массива байт

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Параметры сохранения растра (Интерфейсы ksRasterFormatParam, IRasterFormatParam) ](ksrasterformatparam.html) > [IRasterFormatParam - свойства ](ksrasterformatparam_props.html) |  Scroll [ [ [ ](ksrasterformatparam_saveworkarea.html "К следующему разделу")](ksrasterformatparam_props.html "На уровень выше")](ksrasterformatparam_returnresultasarraybytes.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksrasterformatparam.html)

Тип данных: VARIANT

Синтаксис:

resultArrayBytes = Object.resultArrayBytes | Получить свойство([* ](1.html))  
---|---  
Object.resultArrayBytes = resultArrayBytes | Установить свойство ([* ](1.html))  
resultArrayBytes = Object.GetResultArrayBytes() | Получить свойство ([**](2.html))  
Object.SetResultArrayBytes( resultArrayBytes ) | Установить свойство ([**](2.html))  
  
Примечание:

•Для одностраничного растра возвращается массив байт VT_ARRAY | VT_UI1.

•Для многостраничного растра возвращается массив VT_ARRAY | VT_VARIANT, каждая страница добавляется отдельным элементом в массив ввиде массива байт VT_ARRAY | VT_UI1.

Подразделы:

(отсутствуют)
