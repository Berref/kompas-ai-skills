# ksGetQualityContensParam - Получить параметры квалитета

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksgetsystemcontrolstartresult.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksgetqualitynames.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksGetQualityContensParam](ksgetqualitycontensparam.html).

Синтаксис Automation:

long ksGetQualityContensParam (BSTR name, LPDISPATCH param, short inMM);

Входные параметры:

name | \- поле допуска,  
---|---  
inMM | \- размерность параметров minLimit, maxLimit, high, low: 1 - миллиметры, 0 - единицы измерения текущего документа.  
  
Выходной параметр:

param | \- указатель на интерфейс структуры параметров квалитета [ksQualityContensParam](ksqualitycontensparam.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае выбора квалитета,  
---|---  
FALSE | \- отмены выбора или ошибки.  
  
Подразделы:

(отсутствуют)
