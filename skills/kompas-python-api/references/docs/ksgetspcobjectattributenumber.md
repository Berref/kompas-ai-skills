# ksGetSpcObjectAttributeNumber - Получить номер атрибута объекта спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcobjectcolumntext.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcobject.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcObjectAttributeNumber](ksspecification_ksgetspcobjectattributenumber.html).

Синтаксис:

double ksGetSpcObjectAttributeNumber (reference spcObj);

Входные параметры:

spcObj | \- объект спецификации.  
---|---  
  
Возвращаемое значение:

| \- Номер атрибута.  
---|---  
  
Примечания:

Если spcObj = 0, то возвращается номер редактируемого в текущий момент

объекта спецификации, т.е. внутри блока:

ksSpcObjectEdit(...);

ksGetSpcObjectAttributeNumber(...);

ksSpcObjectEnd();

Подразделы:

(отсутствуют)
