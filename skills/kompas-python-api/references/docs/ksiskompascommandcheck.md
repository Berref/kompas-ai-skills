# ksIsKompasCommandCheck - Проверить нажата ли кнопка команды

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](ksiskompascommandenable.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](ksisexportavailable.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при использовании Automation – [KompasObject::ksIsKompasCommandCheck](kompasobject_ksiskompascommandcheck.html).

Синтаксис:

int LIB_FUNC ksIsKompasCommandCheck (long commandID);

Входные параметры:

commandID | \- константа из перечисления [ProcessTypeEnum](processtypeenum.html) или [ksKompasCommandEnum](kskompascommandenum.html).  
---|---  
  
Возвращаемое значение:

1 | \- кнопка нажата,  
---|---  
0 | \- кнопка отжата.  
  
Подразделы:

(отсутствуют)
