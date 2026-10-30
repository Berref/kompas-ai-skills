# ksGetSpcSectionName - Получить название раздела спецификации, которому принадлежит указанный объект спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcsectionnamew.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcpropertyfill.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetspcsectionname_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcSectionName](ksspecification_ksgetspcsectionname.html).

Синтаксис:

int ksGetSpcSectionName (reference spcObj, char* name, int size);

Входной параметр:

spcObj | \- указатель на объект спецификации.  
---|---  
  
Выходные параметры:

name | \- буфер для имени раздела,  
---|---  
size | \- размер буфера.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [ksGetSpcSectionNameW](ksgetspcsectionnamew.html).

Подразделы:

(отсутствуют)
