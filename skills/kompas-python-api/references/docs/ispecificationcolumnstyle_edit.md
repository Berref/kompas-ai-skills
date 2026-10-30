# Edit - Редактируемая колонка в данном разделе

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumnStyle ](ispecificationcolumnstyle.html) > [ISpecificationColumnStyle - свойства ](ispecificationcolumnstyle_props.html) |  Scroll [ [ [ ](ispecificationcolumnstyle_maxvalue.html "К следующему разделу")](ispecificationcolumnstyle_props.html "На уровень выше")](ispecificationcolumnstyle_columntype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumnstyle.html)

Тип данных: BOOL

Синтаксис Automation:

Edit = iObject.Edit | Получить свойство ([* ](1.html))  
---|---  
Edit = iObject.GetEdit() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Edit (&Edit) | Получить свойство  
---|---  
  
Значения свойства:

TRUE | \- в колонку можно вводить данные,  
---|---  
FALSE | \- заполнение колонки в настраиваемом разделе запрещено.  
  
Примечание:

1\. Используется только для колонок, полученных у стиля раздела спецификации [ISpecificationSectionStyle](ispecificationsectionstyle.html)..

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
