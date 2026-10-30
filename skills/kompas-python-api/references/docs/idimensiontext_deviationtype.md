# DeviationType - Тип отклонений

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Элементы обозначений ](bb2348381.html) > [Интерфейс IDimensionText ](idimensiontext.html) > [IDimensionText - свойства ](idimensiontext_props.html) |  Scroll [ [ [ ](idimensiontext_hastolerance.html "К следующему разделу")](idimensiontext_props.html "На уровень выше")](idimensiontext_deviationon.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idimensiontext.html)

Тип данных: Из перечисления [ksDimensionDeviationEnum](ksdimensiondeviationenum.html)

Синтаксис Automation:

DeviationType = Object.DeviationType | Получить свойство([* ](1.html))  
---|---  
Object.DeviationType = DeviationType | Установить свойство ([* ](1.html))  
DeviationType = Object.GetDeviationType() | Получить свойство ([**](2.html))  
Object.SetDeviationType( DeviationType ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_DeviationType( &DeviationType ) | Получить свойство([* ](1.html))  
---|---  
Object.put_DeviationType( DeviationType ) | Установить свойство ([* ](1.html))  
  
Примечание:

Установите значение свойства равным:

•ksDimDeviation, если требуется внести в размерную надпись предельные отклонения размера,

•ksDimLimits, если требуется внести предельные значения размера (предельные значения записываются одно над другим) или

•ksDimLineLimits, если требуется внести предельные значения размера (предельные значения записываются друг за другом через дефис).

Отклонения или предельные значения размера вычисляются автоматически в соответствии с выбранным квалитетом и номинальным значением размера. При необходимости вы можете ввести значения отклонений или пределов вручную.

Если значения отклонений равны по модулю, но отличаются по знаку, то перед значением отклонения отображается знак ±.

После ввода отклонений или пределов вручную поле Квалитет очищается.

Подразделы:

(отсутствуют)
