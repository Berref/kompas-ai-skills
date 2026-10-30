# ksSetSpcSheetSB - Установить динамический массив листов сборочного чертежа, подключенных к спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](kssettuningspcstyleparam.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](kssetspcpropertyfill.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetspcsheetsb_kssetspcsheetsb_example.html)

Аналог данной функции при использовании Automation - метод [ksSpcDocument::ksSetSpcSheetSB](ksspcdocument_kssetspcsheetsb.html).

Синтаксис:

int ksSetSpcSheetSB (reference spcDoc, reference arr);

Входной параметр:

spcDoc | \- указатель на спецификацию,  
---|---  
arr | \- указатель на динамический массив типа CHAR_STR_ARR или CHAR_STR_ARR_W.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
