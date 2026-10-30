# ksCreateQualityIterator - Создать итератор по квалитетам

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Размеры и технологические обозначения ](cm1742473.html) > [Функции построения размеров /обозначений ](dims_signs_fncts_common.html) |  Scroll [ [ [ ](ksexecqualitydialog.html "К следующему разделу")](dims_signs_fncts_common.html "На уровень выше")](kscentremarker.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksIterator::ksCreateQualityIterator](ksiterator_kscreatequalityiterator.html)

Синтаксис:

reference ksCreateQualityIterator (unsigned char system,

unsigned char withLimitation);

Входные параметры:

system | \- система допуска 1 - система отверстия, 0 - система вала,  
---|---  
withLimitation | \- признак учета ограничений, наложенных в системе: 0 - без учёта ограничений, 1 - с учётом ограничений.  
  
Возвращаемое значение:

указатель на итератор | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
