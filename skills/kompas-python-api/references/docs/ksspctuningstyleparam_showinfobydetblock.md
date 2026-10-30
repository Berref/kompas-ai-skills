# showInfoByDetBlock - Признак, определяющий порядок представления информации в групповой спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ спецификация (Интерфейс ksSpcDocument) ](ksspcdocument.html) > [ksSpcDocument - методы ](ck1881939.html) > [Параметры объектов спецификации ](ck1727663.html) > [Настройки спецификации (Интерфейс ksSpcTuningStyleParam) ](ksspctuningstyleparam.html) > [ksSpcTuningStyleParam - свойства ](ksspctuningstyleparam_props.html) |  Scroll [ [ [ ](ksspctuningstyleparam_showsectionname.html "К следующему разделу")](ksspctuningstyleparam_props.html "На уровень выше")](ksspctuningstyleparam_ispolnon.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspctuningstyleparam.html)

Тип данных: short

Значения свойства:

0 | \- выдавать информацию блоками,  
---|---  
1 | \- выдавать информацию по объектам.  
  
Синтаксис Automation:

showInfoByDetBlock = iSpcTuningStyleParam.showInfoByDetBlock | Получить свойство ([* ](1.html))  
---|---  
iSpcTuningStyleParam.showInfoByDetBlock = showInfoByDetBlock | Установить свойство ([* ](1.html))  
showInfoByDetBlock = iSpcTuningStyleParam.GetShowInfoByDetBlock() | Получить свойство ([**](2.html))  
iSpcTuningStyleParam.SetShowInfoByDetBlock(showInfoByDetBlock) | Установить свойство ([**](2.html))  
  
Примечания:

1\. Значение данного свойства учитывается, только если количество исполнений больше, чем количество колонок, предназначенных для записи количества на исполнение.

2\. Значение данного свойства используется только для групповой спецификации (вариант Б).

Подразделы:

(отсутствуют)
