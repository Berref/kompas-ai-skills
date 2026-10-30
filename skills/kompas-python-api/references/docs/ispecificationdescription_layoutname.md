# LayoutName - Имя файла библиотеки стилей

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescription ](ispecificationdescription.html) > [ISpecificationDescription - свойства ](ispecificationdescription_props.html) |  Scroll [ [ [ ](ispecificationdescription_needrebuild.html "К следующему разделу")](ispecificationdescription_props.html "На уровень выше")](ispecificationdescription_delegatemode.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescription.html)

Тип данных: BSTR

Синтаксис Automation:

LayoutName = iObject.LayoutName | Получить свойство ([* ](1.html))  
---|---  
iObject.LayoutName = LayoutName | Установить свойство ([* ](1.html))  
LayoutName = iObject.GetLayoutName() | Получить свойство ([**](2.html))  
iObject.SetLayoutName (LayoutName) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LayoutName (&LayoutName) | Получить свойство  
---|---  
iObject->put_LayoutName (LayoutName) | Установить свойство  
  
Примечание:

1\. Свойство позволяет получить и установить имя библиотеки стилей, из которой будет взят стиль спецификации для данного описания.

2\. После изменения параметров оформления нужно вызвать метод [Update](ispecificationdescription_update.html), чтобы новые данные вступили в силу.

Подразделы:

(отсутствуют)
