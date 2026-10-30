# ksGetAttrRow - Получить строку атрибута

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_ksgetattrtabinfo.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_ksgetattrkeysinfo.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ksGetAttrRow](ksgetattrrow.html).

Синтаксис Automation:

long ksGetAttrRow (reference pAttr,

long rowNumb,

LPDISPATCH flagVisible,

LPDISPATCH columnKeys,

LPDISPATCH value);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
rowNumb | \- номер строки.  
  
Выходной параметр:

value | \- указатель на интерфейс [ksUserParam](ksuserparam.html), куда копируются данные.  
---|---  
flagVisible | \- указатель на интерфейс динамического массива типа LTVARIANT_ARR [ksDynamicArray](ksdynamicarray.html), указывающего флаги видимости ячеек строки,  
columnKeys | \- указатель на интерфейс динамического массива типа LTVARIANT_ARR ksDynamicArray, указывающего ключи строки.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Смотрите также:[ksLtVariant](ksltvariant.html)

Примечание:

1\. Указатель на атрибут reference pAttr может быть получен следующими способами:

•с помощью интерфейса итератора [ksIterator](ksiterator.html) и методов [ksIterator::ksCreateAttrIterator](ksiterator_kscreateattriterator.html), [ksIterator::ksMoveAttrIterator](ksiterator_ksmoveattriterator.html),

•с помощью методов создания атрибутов [ksAttributeObject::ksCreateAttr](ksattributeobject_kscreateattr.html) или выбора атрибутов [ksAttributeObject::ksChoiceAttr](ksattributeobject_kschoiceattr.html).

2\. Перед использованием указатель flagVisible должен быть получен от интерфейса [KompasObject](kompasobject.html) с помощью метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html) с параметром ko_LtVariant.

3\. Перед использованием указатель value должен быть получен от интерфейса [KompasObject](kompasobject.html) с помощью метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html) с параметром ko_UserParam.

4\. Для получения размера данных строки атрибута может быть использован метод [ksAttributeObject::ksGetSizeAttrRow](ksattributeobject_ksgetsizeattrrow.html).

Подразделы:

(отсутствуют)
