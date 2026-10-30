# SpecificationTuning - Настройки спецификации

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationStyle ](ispecificationstyle.html) > [ISpecificationStyle - свойства ](ispecificationstyle_props.html) |  Scroll [ [ [ ](ispecificationstyle_styleid1.html "К следующему разделу")](ispecificationstyle_props.html "На уровень выше")](ispecificationstyle_sortsectiondown.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationstyle.html)

Тип данных: указатель на интерфейс [ISpecificationTuning](ispecificationtuning.html) настроек спецификации

Синтаксис Automation:

SpecificationTuning = iObject.SpecificationTuning | Получить свойство ([* ](1.html))  
---|---  
SpecificationTuning = iObject.GetSpecificationTuning() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SpecificationTuning (&SpecificationTuning) | Получить свойство  
---|---  
  
Примечание:

Свойство доступно только для чтения. Полученные настройки будут соответствовать настройкам, описанным для данного стиля в библиотеке стилей. Для получения настроек описания спецификации в документе надо брать настройки непосредственно у описания [ISpecificationDescription::SpecificationTuning](ispecificationdescription_specificationtuning.html), т.к. они могут отличатся от настроек стиля.

Подразделы:

(отсутствуют)
