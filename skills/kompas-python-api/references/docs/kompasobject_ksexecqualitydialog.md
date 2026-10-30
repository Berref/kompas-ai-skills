# ksExecQualityDialog - Вызов диалога Выбор квалитета

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksgetapplication7.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksexecutelibrarycommand.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksExecQualityDialog](ksexecqualitydialog.html).

Синтаксис Automation:

BOOL ksExecQualityDialog( long HWindow, BSTR curQual, double * dimValue, long inMM, LPDISPATCH param );

Входные параметры:

HWindow | \- дескриптор окна,  
---|---  
curQual | \- текущее значение квалитета,  
dimValue | \- значение для которого требуется выбрать квалитет или NULL,  
inMM | \- размерность параметров dimValue, high, low: 1 - миллиметры, 0 - единицы измерения текущего документа.  
  
Выходной параметр:

param | \- указатель на интерфейс структуры параметров квалитета [ksQualityContensParam](ksqualitycontensparam.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае выбора квалитета,  
---|---  
FALSE | \- отмены выбора или ошибки.  
  
Подразделы:

(отсутствуют)
