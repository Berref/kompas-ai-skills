# Subsection - Номер подраздела

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationObject ](ispecificationobject.html) > [ISpecificationObject - свойства ](ispecificationobject_props.html) |  Scroll [ [ [ ](ispecificationobject_uniquenumber.html "К следующему разделу")](ispecificationobject_props.html "На уровень выше")](ispecificationobject_state.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationobject.html)

Тип данных: long

Синтаксис Automation:

Subsection = iObject.Subsection | Получить свойство ([* ](1.html))  
---|---  
iObject.Subsection = Subsection | Установить свойство ([* ](1.html))  
Subsection = iObject.GetSubsection() | Получить свойство ([**](2.html))  
iObject.SetSubsection (Subsection) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Subsection (&Subsection) | Получить свойство  
---|---  
iObject->put_Subsection (Subsection) | Установить свойство  
  
Примечание:

1\. Свойство доступно только для базового и вспомогательного объекта спецификации.

2\. Изменение этого свойства вступит в силу после вызова метода [ISpecificationObject::Update](ispecificationobject_update.html).

Подразделы:

(отсутствуют)
