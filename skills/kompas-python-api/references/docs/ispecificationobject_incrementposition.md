# IncrementPosition - Позиция объекта возрастает

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationObject ](ispecificationobject.html) > [ISpecificationObject - свойства ](ispecificationobject_props.html) |  Scroll [ [ [ ](ispecificationobject_nestedblock.html "К следующему разделу")](ispecificationobject_props.html "На уровень выше")](ispecificationobject_firstonsheet.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationobject.html)

Тип данных: BOOL

Синтаксис Automation:

IncrementPosition = iObject.IncrementPosition | Получить свойство ([* ](1.html))  
---|---  
iObject.IncrementPosition = IncrementPosition | Установить свойство ([* ](1.html))  
IncrementPosition = iObject.GetIncrementPosition() | Получить свойство ([**](2.html))  
iObject.SetIncrementPosition (IncrementPosition) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_IncrementPosition (&IncrementPosition) | Получить свойство  
---|---  
iObject->put_IncrementPosition (IncrementPosition) | Установить свойство  
  
Значения свойства:

TRUE | \- номер позиции объекта должен быть на единицу больше номера позиции предшествующего ему объекта,  
---|---  
FALSE | \- номер позиции объекта совпадает с номером позиции предыдущего объекта.  
  
Примечание:

1\. Свойство доступно только для базового и вспомогательного объекта спецификации.

2\. Изменение этого свойства вступит в силу после вызова метода [ISpecificationObject::Update](ispecificationobject_update.html).

Подразделы:

(отсутствуют)
