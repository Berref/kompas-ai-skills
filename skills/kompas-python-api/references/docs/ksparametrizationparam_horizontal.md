# horizontal - Горизонтальность

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс параметров параметризации группы объектов (Интерфейсы ksParametrizationParam, IParametrizationParam) ](ksparametrizationparam.html) > [ksParametrizationParam - свойства ](ksparametrizationparam_props.html) |  Scroll [ [ [ ](ksparametrizationparam_nearestpoints.html "К следующему разделу")](ksparametrizationparam_props.html "На уровень выше")](ksparametrizationparam_anglelimit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksparametrizationparam.html)

Тип данных: VARIANT_BOOL

Синтаксис Automation:

horizontal = iParametrizationParam.horizontal | Получить свойство ([* ](1.html))  
---|---  
iParametrizationParam.horizontal = horizontal | Установить свойство ([* ](1.html))  
horizontal = iParametrizationParam.GetHorizontal() | Получить свойство ([**](2.html))  
iParametrizationParam.SetHorizontal (horizontal) | Установить свойство ([**](2.html))  
  
Примечание:

1\. Если horizontal = TRUE, то на горизонтальные отрезки в группе накладывается ограничения на горизонтальность.

2\. Отклонение от горизонтали [angleLimit](ksparametrizationparam_anglelimit.html) должно быть в интервале [0..10] градусов.

Подразделы:

(отсутствуют)
