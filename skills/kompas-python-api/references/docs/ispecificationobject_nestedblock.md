# NestedBlock - Номер блока вложенных разделов

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationObject ](ispecificationobject.html) > [ISpecificationObject - свойства ](ispecificationobject_props.html) |  Scroll [ [ [ ](ispecificationobject_nestedsection.html "К следующему разделу")](ispecificationobject_props.html "На уровень выше")](ispecificationobject_incrementposition.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationobject.html)

Тип данных: long

Синтаксис Automation:

NestedBlock = iObject.NestedBlock | Получить свойство ([* ](1.html))  
---|---  
iObject.NestedBlock = NestedBlock | Установить свойство ([* ](1.html))  
NestedBlock = iObject.GetNestedBlock() | Получить свойство ([**](2.html))  
iObject.SetNestedBlock (NestedBlock) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_NestedBlock (&NestedBlock) | Получить свойство  
---|---  
Object->put_NestedBlock (NestedBlock) | Установить свойство  
  
Примечание:

1\. Свойство доступно только для базового и вспомогательного объекта спецификации.

2\. Изменение этого свойства вступит в силу после вызова метода [ISpecificationObject::Update](ispecificationobject_update.html).

Подразделы:

(отсутствуют)
