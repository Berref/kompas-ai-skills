# Табличный атрибут (Интерфейс ksAttributeParam)

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейсы параметров атрибутов ](ck1769035.html) |  Scroll [ [ [ ](ksattributeparam_props.html "К следующему разделу")](ck1769035.html "На уровень выше")](ksattributetypeparam_setcolumns.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров атрибута.

Аналог данных параметров при использовании API экспортных функций - [ksAttribute](structksattribute.html).

Примечание:

1\. Перед использованием указатель на интерфейс должен быть определен с помощью метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html) с параметром ko_Attribute.

2\. При создании типа атрибута ключам key1 - key4 могут быть присвоены нулевые значения. Если заданы ненулевые значения ключей или одного из ключей, эти значения могут быть использованы в дальнейшем как дополнительные идентификаторы для поиска атрибута с помощью итератора по атрибутам [ksIterator::ksCreateAttrIterator](ksiterator_kscreateattriterator.html). При присвоении значений ключам рекомендуется для ключей key1, key3 присваивать код, идентифицирующий разработчика, для ключа key2 - код атрибута, для ключа key4 - системный код. Значения параметра key4 от 0 до 1000 зарезервированы за ЗАО "АСКОН".

3\. Значения ключей атрибута могут быть получены с помощью метода [ksAttributeObject::ksGetAttrKeysInfo](ksattributeobject_ksgetattrkeysinfo.html).

Смотрите также [KompasObject](kompasobject.html)

Подразделы:

[ksAttributeParam - свойства ](ksattributeparam_props.html)

[ksAttributeParam - методы ](ksattributeparam_methods.html)
