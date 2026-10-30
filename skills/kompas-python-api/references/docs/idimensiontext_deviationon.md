# DeviationOn - Включить отклонения

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Элементы обозначений ](bb2348381.html) > [Интерфейс IDimensionText ](idimensiontext.html) > [IDimensionText - свойства ](idimensiontext_props.html) |  Scroll [ [ [ ](idimensiontext_deviationtype.html "К следующему разделу")](idimensiontext_props.html "На уровень выше")](idimensiontext_brackets.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idimensiontext.html)

Тип данных: BOOL

Синтаксис Automation:

DeviationOn = Object.DeviationOn | Получить свойство([* ](1.html))  
---|---  
Object.DeviationOn = DeviationOn | Установить свойство ([* ](1.html))  
DeviationOn = Object.GetDeviationOn() | Получить свойство ([**](2.html))  
Object.SetDeviationOn( DeviationOn ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_DeviationOn( &DeviationOn ) | Получить свойство([* ](1.html))  
---|---  
Object.put_DeviationOn( DeviationOn ) | Установить свойство ([* ](1.html))  
  
Примечание:

Установите свойство в TRUE, чтобы отклонения или пределы были отрисованы в размерной надписи. Если пределы включены в размерную надпись, а квалитет нет, то номинальное значение в размерной надписи не отображается.

Если отображение предельных значений размера включено, а квалитет не задан, то изменение геометрии размера (например, при перестроении ассоциативного размера) не приводит к пересчету предельных значений.

Подразделы:

(отсутствуют)
