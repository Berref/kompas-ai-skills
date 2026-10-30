# Active - Текущее описание

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescriptions ](ispecificationdescriptions.html) > [ISpecificationDescriptions - свойства ](ispecificationdescriptions_props.html) |  Scroll [ [ [ ](ispecificationdescriptions_activefromlibstyle.html "К следующему разделу")](ispecificationdescriptions_props.html "На уровень выше")](ispecificationdescriptions_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescriptions.html)

Тип данных: Указатель на интерфейс [ISpecificationDescription](ispecificationdescription.html) описания спецификации

Синтаксис Automation:

Description = iObject.Active | Получить свойство ([* ](1.html))  
---|---  
Description = iObject.GetActive() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Active (&Description) | Получить свойство  
---|---  
  
Примечание:

1\. Если в документе нет описаний спецификаций, возвращается NULL.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
