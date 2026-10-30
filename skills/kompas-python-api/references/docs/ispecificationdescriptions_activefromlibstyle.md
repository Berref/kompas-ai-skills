# ActiveFromLibStyle - Текущее описание, соответствующее библиотечному стилю

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescriptions ](ispecificationdescriptions.html) > [ISpecificationDescriptions - свойства ](ispecificationdescriptions_props.html) |  Scroll [ [ [ ](ispecificationdescriptions_description.html "К следующему разделу")](ispecificationdescriptions_props.html "На уровень выше")](ispecificationdescriptions_active.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescriptions.html)

Тип данных: Указатель на интерфейс [ISpecificationDescription](ispecificationdescription.html)

Синтаксис Automation:

ActiveFromLibStyle = Object.ActiveFromLibStyle | Получить свойство ([* ](1.html))  
---|---  
ActiveFromLibStyle = Object.GetActiveFromLibStyle() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ActiveFromLibStyle( &ActiveFromLibStyle ) | Получить свойство  
---|---  
  
Возвращаемое значение:

\ | \- если текущее описание соответствует своему описанию-источнику в библиотеке, то просто возвращается оно же,  
---|---  
| \- если текущее описание не соответствует своему описанию-источнику в библиотеке, то возвращается новое описание, созданное по описанию-источнику и сделанное текущим,  
| \- если текущего описания нет или для текущего описания не найдено описание-источник (не найдена библиотека-источник), то возвращается NULL.  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
