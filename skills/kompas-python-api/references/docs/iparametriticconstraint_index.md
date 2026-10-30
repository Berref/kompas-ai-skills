# Index - Индекс точки на объекте (начинается с 0, у дуги и окружности 0-центр)

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Ограничения ](bb2391397.html) > [Интерфейс IParametriticConstraint ](iparametriticconstraint.html) > [IParametriticConstraint - свойства ](iparametriticconstraint_props.html) |  Scroll [ [ [ ](iparametriticconstraint_minutes.html "К следующему разделу")](iparametriticconstraint_props.html "На уровень выше")](iparametriticconstraint_expression.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparametriticconstraint.html)

Тип данных: long

Синтаксис Automation:

Index = iObject.Index | Получить свойство([* ](1.html))  
---|---  
iObject.Index = Index | Установить свойство ([* ](1.html))  
Index = iObject.GetIndex() | Получить свойство ([**](2.html))  
iObject.SetIndex(Index) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Index = iObject->get_Index() | Получить свойство  
---|---  
iObject->put_Index(Index) | Установить свойство  
  
Примечание:

1\. Свойство позволяет установить и получить индекс точки на данном графическом объекте. Применяется, например, для ограничения "Совпадение двух точек"(ksCMergePoints).

2\. Изменение параметра возможно на этапе создания ограничения.

Подразделы:

(отсутствуют)
