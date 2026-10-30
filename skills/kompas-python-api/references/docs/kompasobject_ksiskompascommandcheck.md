# ksIsKompasCommandCheck - Проверить, нажата ли кнопка команды

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksiskompascommandenable.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksget3ddocumentfromref.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Аналог данного метода при использовании API экспортных функций - [ksIsKompasCommandCheck](ksiskompascommandcheck.html).

Синтаксис Automation:

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
