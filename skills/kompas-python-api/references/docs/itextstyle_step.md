# Step - Шаг строк

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс ITextStyle ](itextstyle.html) > [ITextStyle - свойства ](itextstyle_props.html) |  Scroll [ [ [ ](itextstyle_step1.html "К следующему разделу")](itextstyle_props.html "На уровень выше")](itextstyle_rightedge.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextstyle.html)

Тип данных: double

Синтаксис Automation:

Step = iObject.Step | Получить свойство([* ](1.html))  
---|---  
iObject.Step = Step | Установить свойство ([* ](1.html))  
Step = iObject.GetStep() | Получить свойство ([**](2.html))  
iObject.SetStep (Step) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Step (&Step) | Получить свойство  
---|---  
iObject->put_Step(Step) | Установить свойство  
  
Примечание:

1\. Свойство позволяет получить/изменить шаг строк (расстояние между строками текста).

2\. Значение шага задается в миллиметрах.

3\. Свойство используется для стиля, полученного через методы интерфейса [ISpecificationTuning](ispecificationtuning.html).

Подразделы:

(отсутствуют)
