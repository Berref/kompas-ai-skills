# Variable - Имя переменной

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Ограничения ](bb2391397.html) > [Интерфейс IParametriticConstraint ](iparametriticconstraint.html) > [IParametriticConstraint - свойства ](iparametriticconstraint_props.html) |  Scroll [ [ [ ](iparametriticconstraint_methods.html "К следующему разделу")](iparametriticconstraint_props.html "На уровень выше")](iparametriticconstraint_value.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparametriticconstraint.html)

Тип данных: BSTR (строка)

Синтаксис Automation:

Variable = iObject.Variable | Получить свойство([* ](1.html))  
---|---  
iObject.Variable = Variable | Установить свойство ([* ](1.html))  
Variable = iObject.GetVariable() | Получить свойство ([**](2.html))  
iObject.SetVariable(Variable) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Variable = iObject->get_Variable() | Получить свойство  
---|---  
iObject->put_Variable(Variable) | Установить свойство  
  
Примечание:

1\. Свойство позволяет установить и получить имя переменной. Используется только для ограничения "Размер с переменной" (ksCDimWithVariable).

2\. При создании ограничения ksCDimWithVariable автоматически присваивается уникальное имя переменной. При установке своего имени нужно следить за уникальностью имени самостоятельно. Иначе ограничение не создастся и взведется ошибка "Ограничение создать нельзя. Недопустимое имя переменной."

3\. Изменение параметра возможно на этапе создания ограничения.

Подразделы:

(отсутствуют)
