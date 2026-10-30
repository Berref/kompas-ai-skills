# ksAddAttrRow - Добавить строку к табличному атрибуту неопределенной длины

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_kschoiceattr.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ksAddAttrRow](ksaddattrrow.html).

Синтаксис Automation:

long ksAddAttrRow (reference pAttr,

long rowNumb,

LPDISPATCH flagVisible,

LPDISPATCH value,

BSTR password);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
rowNumb | \- номер строки,  
flagVisible | \- указатель на интерфейс динамического массива типа LTVARIANT_ARR [ksDynamicArray](ksdynamicarray.html), указывающего флаги видимости ячеек строки,  
value | \- указатель на интерфейс [ksUserParam](ksuserparam.html), откуда копируются данные,  
password | \- пароль атрибута.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Смотрите также [ksLtVariant](ksltvariant.html)

Примечание.

1\. Указатель на атрибут reference pAttr может быть получен следующими способами:

•с помощью интерфейса итератора [ksIterator](ksiterator.html) и методов [ksIterator::ksCreateAttrIterator](ksiterator_kscreateattriterator.html), [ksIterator::ksMoveAttrIterator](ksiterator_ksmoveattriterator.html),

•с помощью методов создания атрибутов [ksAttributeObject::ksCreateAttr](ksattributeobject_kscreateattr.html) или выбора атрибутов [ksAttributeObject::ksChoiceAttr](ksattributeobject_kschoiceattr.html).

2\. Перед использованием указатель flagVisible должен быть получен от интерфейса [KompasObject](kompasobject.html) с помощью метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html) с параметром ko_LtVariant, методов интерфейса [ksLtVariant](ksltvariant.html), [ksDynamicArray](ksdynamicarray.html).

3\. Перед использованием указатель value должен быть получен от интерфейса [KompasObject](kompasobject.html) с помощью метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html) с параметром ko_UserParam с последующим наполнением массива с помощью методов интерфейса [ksUserParam](ksuserparam.html), [ksLtVariant](ksltvariant.html), [ksDynamicArray](ksdynamicarray.html).

Подразделы:

(отсутствуют)
