# SectionOn - Деление на разделы

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationStyle ](ispecificationstyle.html) > [ISpecificationStyle - свойства ](ispecificationstyle_props.html) |  Scroll [ [ [ ](ispecificationstyle_sortsectiondown.html "К следующему разделу")](ispecificationstyle_props.html "На уровень выше")](ispecificationstyle_sections.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationstyle.html)

Тип данных: BOOL

Синтаксис Automation:

SectionOn = iObject.SectionOn | Получить свойство ([* ](1.html))  
---|---  
SectionOn = iObject.GetSectionOn() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SectionOn (&SectionOn) | Получить свойство  
---|---  
  
Значения свойства:

TRUE | \- разбиение на разделы включено, все объекты будут располагаться в своем разделе,  
---|---  
FALSE | \- разбиение на разделы выключено.  
  
Примечание:

1\. Позволяет получить признак разбиения спецификации на разделы.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
