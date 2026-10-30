# AttributesEx - Массив атрибутов документа в виде массива SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) > [Интерфейс IKompasDocument3D ](ikompasdocument3d.html) > [IKompasDocument3D - свойства ](ikompasdocument3d_props.html) |  Scroll [ [ [ ](ikompasdocument3d_choosemanager.html "К следующему разделу")](ikompasdocument3d_props.html "На уровень выше")](ikompasdocument3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d.html)

Тип данных: VARIANT

Синтаксис Automation:

AttributesEx = Object.AttributesEx( Key1, Key2, Key3, Key4, Numb, Objects, SourcePart ) | Получить свойство ([* ](1.html))  
---|---  
AttributesEx = Object.GetAttributesEx( Key1, Key2, Key3, Key4, Numb, Objects, SourcePart ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_AttributesEx( Key1, Key2, Key3, Key4, Numb, Objects, SourcePart, &AttributesEx ) | Получить свойство  
---|---  
  
Входные параметры:

key1, key2, key3, key4 | \- ключи атрибута,  
---|---  
Numb | \- уникальный номер типа атрибута,  
Objects | \- массив VT_ARRAY | VT_DISPATCH объектов, для которых назначается атрибут,  
SourcePart | \- указатель на интерфейс вставки детали [IPart](kspart.html).  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
