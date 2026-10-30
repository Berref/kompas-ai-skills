# Expression - Выражение

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Ограничения ](bb2391397.html) > [Интерфейс IParametriticConstraint ](iparametriticconstraint.html) > [IParametriticConstraint - свойства ](iparametriticconstraint_props.html) |  Scroll [ [ [ ](iparametriticconstraint_index.html "К следующему разделу")](iparametriticconstraint_props.html "На уровень выше")](iparametriticconstraint_degrees.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparametriticconstraint.html)

Тип данных: BSTR (строка)

Синтаксис Automation:

Expression = iObject.Expression | Получить свойство([* ](1.html))  
---|---  
iObject.Expression = Expression | Установить свойство ([* ](1.html))  
Expression = iObject.GetExpression() | Получить свойство ([**](2.html))  
iObject.SetExpression(Expression) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Expression = iObject->get_Expression() | Получить свойство  
---|---  
iObject->put_Expression(Expression) | Установить свойство  
  
Примечание:

1\. Свойство позволяет установить и получить выражение. Используется только для ограничения "Размер с переменной" (ksCDimWithVariable).

2\. Изменение параметра возможно на этапе создания ограничения.

Подразделы:

(отсутствуют)
