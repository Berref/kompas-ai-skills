# Objects - Объекты спецификации

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescription ](ispecificationdescription.html) > [ISpecificationDescription - свойства ](ispecificationdescription_props.html) |  Scroll [ [ [ ](ispecificationdescription_performancecount.html "К следующему разделу")](ispecificationdescription_props.html "На уровень выше")](ispecificationdescription_needrebuild.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescription.html)

Тип данных: VARIANT

Синтаксис Automation:

Objects = iObject.Objects | Получить свойство ([* ](1.html))  
---|---  
Objects = iObject.GetObjects() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Objects (&Objects) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство позволяет получить полный список объектов спецификации. Порядок и состав списка соответствует визуальному отображению данного описания спецификации.

2\. Свойство возвращает переменную типа VARIANT на безопасный массив интерфейсов SAFEARRAY (VT_ARRAY | VT_DISPATCH). Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

3\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
