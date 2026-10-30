# Comment - Комментарий

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Ограничения ](bb2391397.html) > [Интерфейс IParametriticConstraint ](iparametriticconstraint.html) > [IParametriticConstraint - свойства ](iparametriticconstraint_props.html) |  Scroll [ [ [ ](iparametriticconstraint_constrainttype.html "К следующему разделу")](iparametriticconstraint_props.html "На уровень выше")](iparametriticconstraint_bisectorvariant.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparametriticconstraint.html)

Тип данных: BSTR (строка)

Синтаксис Automation:

Comment = iObject.Comment | Получить свойство([* ](1.html))  
---|---  
iObject.Comment = Comment | Установить свойство ([* ](1.html))  
Comment = iObject.GetComment() | Получить свойство ([**](2.html))  
iObject.SetComment(Comment) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Comment = iObject->get_Comment() | Получить свойство  
---|---  
iObject->put_Comment(Comment) | Установить свойство  
  
Примечание:

1\. Свойство позволяет установить и получить комментарий. Используется только для ограничения "Размер с переменной" (ksCDimWithVariable). Комментарий можно установить для размеров при редактировании эскизов.

2\. Изменение параметра возможно на этапе создания ограничения.

Подразделы:

(отсутствуют)
