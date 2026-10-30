# ObjectTextStyle - Стиль текста объекта спецификации

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_performanceblocktextstylefirst.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_nestingblocktextstylenext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: указатель на интерфейс [ITextStyle](itextstyle.html) параметров стиля текста

Синтаксис Automation:

ObjectTextStyle = iObject.ObjectTextStyle | Получить свойство ([* ](1.html))  
---|---  
ObjectTextStyle = iObject.GetObjectTextStyle() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ObjectTextStyle (&ObjectTextStyle) | Получить свойство  
---|---  
  
Примечание:

1\. Позволяет получить параметры шрифта текстовой части объектов спецификации, отличающиеся от параметров шрифта в оформлении. Имеет смысл, если свойство [UserTextStyle](ispecificationtuning_usertextstyle.html) имеет значение TRUE.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
