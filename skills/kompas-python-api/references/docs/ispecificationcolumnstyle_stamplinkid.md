# StampLinkID - Номер ячейки штампа для связи

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumnStyle ](ispecificationcolumnstyle.html) > [ISpecificationColumnStyle - свойства ](ispecificationcolumnstyle_props.html) |  Scroll [ [ [ ](ispecificationcolumnstyle_textdown.html "К следующему разделу")](ispecificationcolumnstyle_props.html "На уровень выше")](ispecificationcolumnstyle_number.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumnstyle.html)

Тип данных: long

Синтаксис Automation:

StampLinkID = iObject.StampLinkID | Получить свойство ([* ](1.html))  
---|---  
StampLinkID = iObject.GetStampLinkID() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_StampLinkID (&StampLinkID) | Получить свойство  
---|---  
  
Значения свойства:

Номер ячейки штампа. |   
---|---  
  
Примечание:

1\. Данное свойство определяет ячейку штампа чертежа детали, данные из которой могут автоматически передаваться в данную колонку спецификации. Например, в колонку Формат можно передавать текст из ячейки Формат штампа чертежа детали.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
