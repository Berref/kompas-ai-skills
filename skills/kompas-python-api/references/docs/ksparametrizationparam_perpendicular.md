# perpendicular - Перпендикулярность

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс параметров параметризации группы объектов (Интерфейсы ksParametrizationParam, IParametrizationParam) ](ksparametrizationparam.html) > [ksParametrizationParam - свойства ](ksparametrizationparam_props.html) |  Scroll [ [ [ ](ksparametrizationparam_pointslimit.html "К следующему разделу")](ksparametrizationparam_props.html "На уровень выше")](ksparametrizationparam_parallel.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksparametrizationparam.html)

Тип данных: VARIANT_BOOL

Синтаксис Automation:

perpendicular = iParametrizationParam.perpendicular | Получить свойство ([* ](1.html))  
---|---  
iParametrizationParam.perpendicular = perpendicular | Установить свойство ([* ](1.html))  
perpendicular = iParametrizationParam.GetPerpendicular() | Получить свойство ([**](2.html))  
iParametrizationParam.SetPerpendicular (perpendicular) | Установить свойство ([**](2.html))  
  
Примечание:

1\. Если perpendicular = TRUE, то на параллельные отрезки в группе накладывается ограничения на перпендикулярность.

2\. Допуск на отклонение от перпендикулярности [angleLimit](ksparametrizationparam_anglelimit.html) должно быть в интервале [0...10] градусов.

Подразделы:

(отсутствуют)
