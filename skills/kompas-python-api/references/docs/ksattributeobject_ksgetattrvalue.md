# ksGetAttrValue - Получить значение ячейки из таблицы атрибута

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_ksgetlibraryattrtypesarray.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_ksgetattrtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ksGetAttrValue](ksgetattrvalue.html).

Синтаксис Automation:

long ksGetAttrValue (reference pAttr,

long rowNumb,

long columnNumb,

LPDISPATCH flagVisible,

LPDISPATCH columnKeys,

LPDISPATCH value);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
rowNumb | \- номер строки,  
columnNumb | \- номер колонки.  
  
Выходной параметр:

value | \- указатель на интерфейс [ksUserParam](ksuserparam.html), куда копируется значение ячейки,  
---|---  
flagVisible | \- указатель на интерфейс динамического массива типа LTVARIANT_ARR [ksDynamicArray](ksdynamicarray.html), указывающего флаги видимости ячеек,  
columnKeys | \- указатель на интерфейс динамического массива типа LTVARIANT_ARR [ksDynamicArray](ksdynamicarray.html), указывающего ключи полей колонки.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Смотрите также:[ksLtVariant](ksltvariant.html)

Примечание

1\. Для нетабличного атрибута номер колонки равен нулю.

2\. Указатель на атрибут reference pAttr может быть получен следующими способами:

•с помощью интерфейса итератора [ksIterator](ksiterator.html) и методов [ksIterator::ksCreateAttrIterator](ksiterator_kscreateattriterator.html), [ksIterator::ksMoveAttrIterator](ksiterator_ksmoveattriterator.html),

•с помощью методов создания атрибутов [ksAttributeObject::ksCreateAttr](ksattributeobject_kscreateattr.html) или выбора атрибутов [ksAttributeObject::ksChoiceAttr](ksattributeobject_kschoiceattr.html).

3\. Перед использованием указатель flagVisible должен быть получен от интерфейса [KompasObject](kompasobject.html) с помощью метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html) с параметром ko_LtVariant.

4\. Перед использованием указатель value должен быть получен от интерфейса [KompasObject](kompasobject.html) с помощью метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html) с параметром ko_UserParam.

5\. Для получения размера данных ячейки атрибута может быть использован метод [ksAttributeObject::ksGetSizeAttrValue](ksattributeobject_ksgetsizeattrvalue.html).

Подразделы:

(отсутствуют)
