# pointsLimit - Допуск на совпадение точек, мм

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс параметров параметризации группы объектов (Интерфейсы ksParametrizationParam, IParametrizationParam) ](ksparametrizationparam.html) > [ksParametrizationParam - свойства ](ksparametrizationparam_props.html) |  Scroll [ [ [ ](ksparametrizationparam_vertical.html "К следующему разделу")](ksparametrizationparam_props.html "На уровень выше")](ksparametrizationparam_perpendicular.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksparametrizationparam.html)

Тип данных: double

Синтаксис Automation:

pointsLimit = iParametrizationParam.pointsLimit | Получить свойство ([* ](1.html))  
---|---  
iParametrizationParam.pointsLimit = pointsLimit | Установить свойство ([* ](1.html))  
pointsLimit = iParametrizationParam.GetPointsLimit() | Получить свойство ([**](2.html))  
iParametrizationParam.SetPointsLimit (pointsLimit) | Установить свойство ([**](2.html))  
  
Примечание:

1\. Значение должно быть в интервале [0...10] мм.

2\. Параметр используется совместно с [nearestPoints](ksparametrizationparam_nearestpoints.html). Если nearestPoints = TRUE, то при совпадении точек у объектов в параметризуемой группе на объекты накладываются ограничения на совпадение точек.

Подразделы:

(отсутствуют)
