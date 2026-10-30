# nearestPoints - Совпадение точек

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс параметров параметризации группы объектов (Интерфейсы ksParametrizationParam, IParametrizationParam) ](ksparametrizationparam.html) > [ksParametrizationParam - свойства ](ksparametrizationparam_props.html) |  Scroll [ [ [ ](ksparametrizationparam_parallel.html "К следующему разделу")](ksparametrizationparam_props.html "На уровень выше")](ksparametrizationparam_horizontal.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksparametrizationparam.html)

Тип данных: VARIANT_BOOL

Синтаксис Automation:

nearestPoints = iParametrizationParam.nearestPoints | Получить свойство ([* ](1.html))  
---|---  
iParametrizationParam.nearestPoints = nearestPoints | Установить свойство ([* ](1.html))  
nearestPoints = iParametrizationParam.GetNearestPoints() | Получить свойство ([**](2.html))  
iParametrizationParam.SetNearestPoints( nearestPoints ) | Установить свойство ([**](2.html))  
  
Примечание:

1\. Если nearestPoints = TRUE, то при совпадении точек у объектов в параметризуемой группе на объекты накладывается ограничения на совпадение точек.

2\. Параметр используется совместно с [pointsLimit](ksparametrizationparam_pointslimit.html).

Подразделы:

(отсутствуют)
