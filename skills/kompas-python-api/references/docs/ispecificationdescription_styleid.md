# StyleID - Номер стиля в библиотеке стилей

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescription ](ispecificationdescription.html) > [ISpecificationDescription - свойства ](ispecificationdescription_props.html) |  Scroll [ [ [ ](ispecificationdescription_methods.html "К следующему разделу")](ispecificationdescription_props.html "На уровень выше")](ispecificationdescription_specificationtuning.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescription.html)

Тип данных: long

Синтаксис Automation:

StyleID = iObject.StyleID | Получить свойство ([* ](1.html))  
---|---  
iObject.StyleID = StyleID | Установить свойство ([* ](1.html))  
StyleID = iObject.GetStyleID() | Получить свойство ([**](2.html))  
iObject.SetStyleID (StyleID) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_StyleID (&StyleID) | Получить свойство  
---|---  
iObject->put_StyleID (StyleID) | Установить свойство  
  
Примечание:

1\. Свойство позволяет получить и установить номер стиля в библиотеке стилей, из которой будет взят стиль спецификации для данного описания (см. [LayoutName](ispecificationdescription_layoutname.html)).

2\. После изменения параметров оформления нужно вызвать метод [Update](ispecificationdescription_update.html), чтобы новые данные вступили в силу.

Подразделы:

(отсутствуют)
