# ksSetSpcObjectAttributeNumber - Установить номер атрибута объекта спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](kssetspcobjectcolumntext.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](kssetspcdescriptionw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksSetSpcObjectAttributeNumber](ksspecification_kssetspcobjectattributenumber.html).

Синтаксис:

int ksSetSpcObjectAttributeNumber (reference spcObj, double attrNumber);

Входные параметры:

spcObj | \- объект спецификации,  
---|---  
attrNumber | \- номер атрибута.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.- в случае неудачи.  
  
Примечания:

Если spcObj = 0, то возвращается номер редактируемого в текущий момент

объекта спецификации, т.е. внутри блока:

ksSpcObjectEdit(...);

...

...

ksSpcObjectEnd();

Подразделы:

(отсутствуют)
