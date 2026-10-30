# PartsEx - Массив SAFEARRAY компонентов

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - свойства ](ipart7_props.html) |  Scroll [ [ [ ](ipart7_partsgroupnumber.html "К следующему разделу")](ipart7_props.html "На уровень выше")](ipart7_parts.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

[Пример...](partsex_instancecount_example.html)

Тип данных: VARIANT

Синтаксис Automation:

Objects = iObject.PartsEx( ObjType ) | Получить свойство ([* ](1.html))  
---|---  
Objects = iObject.GetPartsEx( ObjType ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_PartsEx( &Objects ) | Получить свойство  
---|---  
  
Входные параметры:

ObjType ( VARIANT) | \- Тип коллекции. В настоящее время может принимать значение константы из перечисления [ksPart7CollectionTypeEnum](kspart7collectiontypeenum.html).  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Коллекция объектов возвращается в виде массива SAFEARRAY объектов LPDISPATCH ( VT_ARRAY | VT_DISPATCH). Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
