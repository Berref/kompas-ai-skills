# ksGetLibraryAttrTypesArray - Получить указатель на динамический массив типов атрибутов типа LIBRARY_ATTR_TYPE_ARR, находящихся в заданной библиотеке типов - ksDynamicArray

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_ksgetsizeattrrow.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_ksgetattrvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ksGetLibraryAttrTypesArray](ksgetlibraryattrtypesarray.html).

Синтаксис Automation:

LPDISPATCH ksGetLibraryAttrTypesArray (BSTR libName);

Входной параметр:

libName | \- имя библиотеки типов атрибутов. Если libname = NULL, то типы атрибутов из текущего документа.  
---|---  
  
Возвращаемое значение:

указатель на интерфейс массива [ksDynamicArray](ksdynamicarray.html) типа LIBRARY_ATTR_TYPE_ARR | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
