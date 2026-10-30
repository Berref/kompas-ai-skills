# NestedSection - Номер вложенного раздела

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationObject ](ispecificationobject.html) > [ISpecificationObject - свойства ](ispecificationobject_props.html) |  Scroll [ [ [ ](ispecificationobject_objecttype.html "К следующему разделу")](ispecificationobject_props.html "На уровень выше")](ispecificationobject_nestedblock.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationobject.html)

Тип данных: long

Синтаксис Automation:

NestedSection = iObject.NestedSection | Получить свойство ([* ](1.html))  
---|---  
iObject.NestedSection = NestedSection | Установить свойство ([* ](1.html))  
iObject.GetNestedSection() | Получить свойство ([**](2.html))  
iObject.SetNestedSection (NestedSection) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_NestedSection (&NestedSection) | Получить свойство  
---|---  
iObject->put_NestedSection (NestedSection) | Установить свойство  
  
Примечание:

1\. Свойство доступно только для базового и вспомогательного объекта спецификации.

2\. Изменение этого свойства вступит в силу после вызова метода [ISpecificationObject::Update](ispecificationobject_update.html).

Подразделы:

(отсутствуют)
