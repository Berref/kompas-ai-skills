# vertical - Вертикальность

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс параметров параметризации группы объектов (Интерфейсы ksParametrizationParam, IParametrizationParam) ](ksparametrizationparam.html) > [ksParametrizationParam - свойства ](ksparametrizationparam_props.html) |  Scroll [ [ [ ](ksparametrizationparam_methods.html "К следующему разделу")](ksparametrizationparam_props.html "На уровень выше")](ksparametrizationparam_pointslimit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksparametrizationparam.html)

Тип данных: VARIANT_BOOL

Синтаксис Automation:

vertical = iParametrizationParam.vertical | Получить свойство ([* ](1.html))  
---|---  
iParametrizationParam.vertical = vertical | Установить свойство ([* ](1.html))  
vertical = iParametrizationParam.GetVertical() | Получить свойство ([**](2.html))  
iParametrizationParam.SetVertical (vertical) | Установить свойство ([**](2.html))  
  
Примечание:

1\. Если vertical = TRUE, то на вертикальные отрезки в группе накладываются ограничения на горизонтальность.

2\. Отклонение от вертикали [angleLimit](ksparametrizationparam_anglelimit.html) должно быть в интервале [0..10] градусов.

Подразделы:

(отсутствуют)
