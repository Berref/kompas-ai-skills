# ksModule3D - Подключить 3D модуль для режима сетевой работы системы

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](kssetcriticalprocess.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](kskompasvariant.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при использовании Automation - [KompasObject::ksModule3D](kompasobject_ksmodule3d.html).

Синтаксис:

int ksModule3D (unsigned char attach);

Входные параметры:

attach | 1 - включить работу с 3D модулем, 0 - отключить.  
---|---  
  
Возвращаемое значение:

1 | \- если был инициирован процесс подключения или отключения 3D модуля,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
