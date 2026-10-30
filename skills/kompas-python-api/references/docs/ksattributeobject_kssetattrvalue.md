# ksSetAttrValue - Установить значение ячейки в таблице атрибута

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_ksvieweditattr.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_kssetattrtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ksSetAttrValue](kssetattrvalue.html).

Синтаксис Automation:

long ksSetAttrValue (reference pAttr,

long rowNumb,

long columnNumb,

LPDISPATCH

flagVisible,

LPDISPATCH columnKeys,

LPDISPATCH value,

BSTR password);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
rowNumb | \- номер строки,  
columnNumb | \- номер колонки,  
flagVisible | \- указатель на интерфейс динамического массива типа LTVARIANT_ARR [ksDynamicArray](ksdynamicarray.html), указывающего флаги видимости ячеек,  
columnKeys | \- указатель на интерфейс динамического массива типа LTVARIANT_ARR [ksDynamicArray](ksdynamicarray.html), указывающего ключи полей колонки,  
value | \- указатель на интерфейс [ksUserParam](ksuserparam.html), откуда копируется значение ячейки,  
password | \- пароль атрибута.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Смотрите также:[ksLtVariant](ksltvariant.html)

Примечание:

1\. Для нетабличного атрибута номер колонки равен нулю.

2\. Указатель на атрибут reference pAttr может быть получен следующими способами:

•с помощью интерфейса итератора [ksIterator](ksiterator.html) и методов [ksIterator::ksCreateAttrIterator](ksiterator_kscreateattriterator.html), [ksIterator::ksMoveAttrIterator](ksiterator_ksmoveattriterator.html),

•с помощью методов создания атрибутов [ksAttributeObject::ksCreateAttr](ksattributeobject_kscreateattr.html) или выбора атрибутов [ksAttributeObject::ksChoiceAttr](ksattributeobject_kschoiceattr.html).

3\. Перед использованием указатель flagVisible должен быть получен от интерфейса [KompasObject](kompasobject.html) с помощью метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html) с параметром ko_LtVariant, методов интерфейса [ksLtVariant](ksltvariant.html), интерфейса [ksDynamicArray](ksdynamicarray.html), метода [ksDynamicArray::ksSetArrayItem](ksdynamicarray_kssetarrayitem.html), [ksDynamicArray::ksAddArrayItem](ksdynamicarray_ksaddarrayitem.html).

4\. Перед использованием указатель value должен быть получен от интерфейса [KompasObject](kompasobject.html) с помощью метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html) с параметром ko_UserParam с последующим наполнением массива с помощью методов интерфейса [ksUserParam](ksuserparam.html), [ksLtVariant](ksltvariant.html), [ksDynamicArray](ksdynamicarray.html).

Подразделы:

(отсутствуют)
