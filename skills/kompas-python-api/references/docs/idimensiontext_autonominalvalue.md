# AutoNominalValue - Автоматическое определение номинального значения размера

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Элементы обозначений ](bb2348381.html) > [Интерфейс IDimensionText ](idimensiontext.html) > [IDimensionText - свойства ](idimensiontext_props.html) |  Scroll [ [ [ ](idimensiontext_brackets.html "К следующему разделу")](idimensiontext_props.html "На уровень выше")](idimensiontext_accuracydecimalscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idimensiontext.html)

Тип данных: BOOL

Синтаксис Automation:

AutoNominalValue = Object.AutoNominalValue | Получить свойство([* ](1.html))  
---|---  
Object.AutoNominalValue = AutoNominalValue | Установить свойство ([* ](1.html))  
AutoNominalValue = Object.GetAutoNominalValue() | Получить свойство ([**](2.html))  
Object.SetAutoNominalValue( AutoNominalValue ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_AutoNominalValue( &AutoNominalValue ) | Получить свойство([* ](1.html))  
---|---  
Object.put_AutoNominalValue( AutoNominalValue ) | Установить свойство ([* ](1.html))  
  
Примечание:

По умолчанию признак включен и задает автоматическое вычисление значения размера. Если признак снят, то значение вводили вручную. При необходимости можно вернуть автоматическое вычисление значения размера. Для этого нужно установить флаг в TRUE. При этом отображаемое значение изменится. Точность отображения автоматически вычисленного значения можно задать в диалоге настройки точности размерных надписей.

Если значение размера введено вручную, то настройка точности на него не влияет.

Подразделы:

(отсутствуют)
