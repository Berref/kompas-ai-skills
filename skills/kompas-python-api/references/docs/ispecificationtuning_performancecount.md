# PerformanceCount - Количество исполнений

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_performancecountinblock.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_performanceblocktextstylenext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: long

Синтаксис Automation:

PerformanceCount = iObject.PerformanceCount | Получить свойство ([* ](1.html))  
---|---  
iObject.PerformanceCount = PerformanceCount | Установить свойство ([* ](1.html))  
PerformanceCount = iObject.GetPerformanceCount() | Получить свойство ([**](2.html))  
iObject.SetPerformanceCount (PerformanceCount) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_PerformanceCount (&PerformanceCount) | Получить свойство  
---|---  
iObject->put_PerformanceCount (PerformanceCount) | Установить свойство  
  
Примечание:

Позволяет указать количество исполнений специфицируемого изделия. Введенное число будет влиять на доступность ячеек "Количество", на исполнение и количество самих этих ячеек.Имеет смысл только при настройке групповых спецификаций.

Подразделы:

(отсутствуют)
