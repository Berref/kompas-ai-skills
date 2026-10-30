# GetSizeAttrValue - Получить длину поля атрибута

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](ksaddattrrow.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](getsizeattrrow.html "К предыдущему разделу")  
---|---  
  
[Пример...](getsizeattrvalue_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksGetSizeAttrValue](ksattributeobject_ksgetsizeattrvalue.html).

Синтаксис:

int GetSizeAttrValue (reference pAttr, unsigned int columnNumb);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
columnNumb | \- номер колонки.  
  
Возвращаемое значение:

длина поля атрибута | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Функция устарела, рекомендуется вместо нее использовать функцию [ksGetSizeAttrValue](ksgetsizeattrvalue.html).

Подразделы:

(отсутствуют)
