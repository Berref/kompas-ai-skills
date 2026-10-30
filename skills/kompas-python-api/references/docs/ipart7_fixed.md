# Fixed - Состояние фиксации компонента

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - свойства ](ipart7_props.html) |  Scroll [ [ [ ](ipart7_hatchparam.html "К следующему разделу")](ipart7_props.html "На уровень выше")](ipart7_filename.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Тип данных: BOOL

Синтаксис Automation:

Fixed = iObject.Fixed | Получить свойство ([* ](1.html))  
---|---  
iObject.Fixed = Fixed | Установить свойство ([* ](1.html))  
Fixed = iObject.GetFixed() | Получить свойство ([**](2.html))  
iObject.SetFixed( Fixed ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Fixed( &Fixed ) | Получить свойство  
---|---  
iObject->put_Fixed( Fixed ) | Установить свойство  
  
Значения свойства:

TRUE | \- компонент зафиксирован,  
---|---  
FALSE | \- компонент не зафиксирован.  
  
Примечание:

Свойство вступает в силу после вызова метода [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
