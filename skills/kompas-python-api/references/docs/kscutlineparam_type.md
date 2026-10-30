# type - Способ задания надписи на линии разреза/сечения

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Линия разреза/сечения (Интерфейс ksCutLineParam) ](kscutlineparam.html) > [ksCutLineParam - свойства ](kscutlineparam_props.html) |  Scroll [ [ [ ](kscutlineparam_x1.html "К следующему разделу")](kscutlineparam_props.html "На уровень выше")](kscutlineparam_style.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutlineparam.html)

Тип данных: short

Значения свойства:

0 | \- текст в виде строки (используется значение свойства [ksCutLineParam::str](kscutlineparam_str.html)),  
---|---  
1 | \- динамический массив компонент текста (используется массив pTextline).  
  
Синтаксис Automation:

type = iCutLineParam.type | Получить свойство ([* ](1.html))  
---|---  
iCutLineParam.type = type | Установить свойство ([* ](1.html))  
type = iCutLineParam.GetType() | Получить свойство ([**](2.html))  
iCutLineParam.SetType(type) | Установить свойство ([**](2.html))  
  
Смотрите также:

[ksCutLineParam::SetpTextline](kscutlineparam_setptextline.html),

[ksCutLineParam::GetpTextline](kscutlineparam_getptextline.html)

Подразделы:

(отсутствуют)
