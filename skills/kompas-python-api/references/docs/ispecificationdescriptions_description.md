# Description - Описание спецификации по имени файла библиотеки оформлений и номеру стиля в библиотеке

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescriptions ](ispecificationdescriptions.html) > [ISpecificationDescriptions - свойства ](ispecificationdescriptions_props.html) |  Scroll [ [ [ ](ispecificationdescriptions_item.html "К следующему разделу")](ispecificationdescriptions_props.html "На уровень выше")](ispecificationdescriptions_activefromlibstyle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescriptions.html)

Тип данных: Указатель на интерфейс [ISpecificationDescription](ispecificationdescription.html) описания спецификации

Синтаксис Automation:

Description = iObject.Description (LayoutName, StyleID) | Получить свойство ([* ](1.html))  
---|---  
Description = iObject.GetDescription (LayoutName, StyleID) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Description (LayoutName, StyleID, &Description) | Получить свойство  
---|---  
  
Входные параметры:

LayoutName | \- имя файла библиотеки оформлений,  
---|---  
StyleID | \- номер стиля в библиотеке оформлений.  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
