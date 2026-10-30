# ksGetLibraryAttrTypesArray - Получить массив типов атрибутов, находящихся в указанной библиотеке

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](ksgetsizeattrrow.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](ksgetattrvaluew.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetlibraryattrtypesarray_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksGetLibraryAttrTypesArray](ksattributeobject_ksgetlibraryattrtypesarray.html).

Синтаксис:

reference ksGetLibraryAttrTypesArray (char * libname);

Входной параметр:

libName | \- имя библиотеки типов атрибутов. Если libname = NULL, то типы атрибутов из текущего документа.  
---|---  
  
Возвращаемое значение:

указатель на динамический массив [ksDynamicArray](ksdynamicarray.html) LIBRARY_ATTR_TYPE_ARR - массив типов атрибутов, находящихся в заданной библиотеке типов | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
