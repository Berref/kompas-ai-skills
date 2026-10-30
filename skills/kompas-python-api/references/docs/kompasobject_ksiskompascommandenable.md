# ksIsKompasCommandEnable - Проверить доступность выполнения команды

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksislibraryenabled.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksiskompascommandcheck.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksIsKompasCommandEnable](ksiskompascommandenable.html).

Синтаксис Automation:

BOOL ksIsKompasCommandEnable (long commandID);

Входные параметры:

commandID | \- константа из перечисления [ProcessTypeEnum](processtypeenum.html) или [ksKompasCommandEnum](kskompascommandenum.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- команда доступна,  
---|---  
FALSE | \- команда недоступна.  
  
Подразделы:

(отсутствуют)
