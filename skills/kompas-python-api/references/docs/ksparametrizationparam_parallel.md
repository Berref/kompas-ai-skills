# parallel - Параллельность

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс параметров параметризации группы объектов (Интерфейсы ksParametrizationParam, IParametrizationParam) ](ksparametrizationparam.html) > [ksParametrizationParam - свойства ](ksparametrizationparam_props.html) |  Scroll [ [ [ ](ksparametrizationparam_perpendicular.html "К следующему разделу")](ksparametrizationparam_props.html "На уровень выше")](ksparametrizationparam_nearestpoints.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksparametrizationparam.html)

Тип данных: VARIANT_BOOL

Синтаксис Automation:

parallel = iParametrizationParam.parallel | Получить свойство ([* ](1.html))  
---|---  
iParametrizationParam.parallel = parallel | Установить свойство ([* ](1.html))  
parallel = iParametrizationParam.GetParallel() | Получить свойство ([**](2.html))  
iParametrizationParam.SetParallel (parallel) | Установить свойство ([**](2.html))  
  
Примечание:

1\. Если parallel = TRUE, то на параллельные отрезки в группе накладывается ограничения на параллельность.

2\. Допуск на отклонение от параллельности [angleLimit](ksparametrizationparam_anglelimit.html) должно быть в интервале [0..10] градусов.

Подразделы:

(отсутствуют)
