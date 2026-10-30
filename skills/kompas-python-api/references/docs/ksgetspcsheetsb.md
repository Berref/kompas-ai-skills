# ksGetSpcSheetSB - Получить динамический массив листов сборочного чертежа, подключенных к спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcsheetsb_w.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcsectionnamew.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetspcsheetsb_kssetspcsheetsb_example.html)

Аналог данной функции при использовании Automation - метод [ksSpcDocument::ksGetSpcSheetSB](ksspcdocument_ksgetspcsheetsb.html).

Синтаксис:

reference ksGetSpcSheetSB (reference spcDoc);

Входной параметр:

spcDoc | \- указатель на спецификацию.  
---|---  
  
Возвращаемое значение:

указатель на динамический массив листов сборочного чертежа типа CHAR_STR_ARR | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
