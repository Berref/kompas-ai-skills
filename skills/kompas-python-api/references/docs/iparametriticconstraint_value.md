# Value - Значение

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Ограничения ](bb2391397.html) > [Интерфейс IParametriticConstraint ](iparametriticconstraint.html) > [IParametriticConstraint - свойства ](iparametriticconstraint_props.html) |  Scroll [ [ [ ](iparametriticconstraint_variable.html "К следующему разделу")](iparametriticconstraint_props.html "На уровень выше")](iparametriticconstraint_valid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparametriticconstraint.html)

Тип данных: double

Синтаксис Automation:

Value = iObject.Value | Получить свойство([* ](1.html))  
---|---  
iObject.Value = Value | Установить свойство ([* ](1.html))  
Value = iObject.GetValue() | Получить свойство ([**](2.html))  
iObject.SetValue(Value) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Value = iObject->get_Value() | Получить свойство  
---|---  
iObject->put_Value(Value) | Установить свойство  
  
Примечание:

1\. Свойство позволяет установить и получить значение. Используется только для ограничения "Размер с переменной" (ksCDimWithVariable).

Установить значение можно, если на объекте есть ограничение "Фиксированный размер"(ksCFixedDim).

2\. Размер не является информационным.

3\. Изменение параметра возможно на этапе создания ограничения.

Подразделы:

(отсутствуют)
