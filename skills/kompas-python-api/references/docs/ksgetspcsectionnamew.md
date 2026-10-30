# ksGetSpcSectionNameW - Получить название раздела спецификации, которому принадлежит указанный объект спецификации (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcsheetsb.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcsectionname.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcSectionName](ksspecification_ksgetspcsectionname.html).

Синтаксис:

int ksGetSpcSectionNameW (reference spcObj, LPWSTR name, int size);

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

При использовании ANSI следует использовать функцию [ksGetSpcSectionName](ksgetspcsectionname.html).

Подразделы:

(отсутствуют)
