# CalculateSum - Рассчитывать сумму значений для колонки

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumnStyle ](ispecificationcolumnstyle.html) > [ISpecificationColumnStyle - свойства ](ispecificationcolumnstyle_props.html) |  Scroll [ [ [ ](ispecificationcolumnstyle_columntype.html "К следующему разделу")](ispecificationcolumnstyle_props.html "На уровень выше")](ispecificationcolumnstyle_attributelibraryname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumnstyle.html)

Тип данных: BOOL

Синтаксис Automation:

CalculateSum = iObject.CalculateSum | Получить свойство ([* ](1.html))  
---|---  
CalculateSum = iObject.GetCalculateSum() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CalculateSum (&CalculateSum) | Получить свойство  
---|---  
  
Значения свойства:

TRUE | \- складывать значения в таблице при вызове команды "Сложить значения в колонках",  
---|---  
FALSE | \- складывать значения в таблице запрещено.  
  
Примечание:

1\. Используется только для колонок со значением типа Вещественный или Целый (см. [ValueType](ispecificationcolumnstyle_valuetype.html)).

2\. Используется только для колонок, полученных у стиля спецификации [ISpecificationStyle](ispecificationstyle.html).

3\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
