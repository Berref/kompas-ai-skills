# MultiplyToCount - При расчете суммы домножать на количество

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumnStyle ](ispecificationcolumnstyle.html) > [ISpecificationColumnStyle - свойства ](ispecificationcolumnstyle_props.html) |  Scroll [ [ [ ](ispecificationcolumnstyle_name.html "К следующему разделу")](ispecificationcolumnstyle_props.html "На уровень выше")](ispecificationcolumnstyle_minvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumnstyle.html)

Тип данных: BOOL

Синтаксис Automation:

MultiplyToCount = iObject.MultiplyToCount | Получить свойство ([* ](1.html))  
---|---  
MultiplyToCount = iObject.GetMultiplyToCount() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_MultiplyToCount (&MultiplyToCount) | Получить свойство  
---|---  
  
Значения свойства:

TRUE | \- перед сложением значение в колонке должно быть умножено на число в колонке "Количество",  
---|---  
FALSE | \- складывать без изменений.  
  
Примечание:

1\. Используется только для колонок со значением типа Вещественный или Целый (см. [ValueType](ispecificationcolumnstyle_valuetype.html)), если [ISpecificationColumnStyle::CalculateSum](ispecificationcolumnstyle_calculatesum.html) равно TRUE.

2\. Используется только для колонок, полученных у стиля спецификации [ISpecificationStyle](ispecificationstyle.html).

3\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
