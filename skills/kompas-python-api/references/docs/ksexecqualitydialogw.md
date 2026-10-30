# ksExecQualityDialogW - Вызов диалога Выбор квалитета (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Размеры и технологические обозначения ](cm1742473.html) > [Функции построения размеров /обозначений ](dims_signs_fncts_common.html) |  Scroll [ [ [ ](ksgetleadershelflength.html "К следующему разделу")](dims_signs_fncts_common.html "На уровень выше")](ksexecqualitydialog.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksExecQualityDialog](kompasobject_ksexecqualitydialog.html).

Синтаксис:

int LIB_FUNC ksExecQualityDialogW( void *HWindow, LPWSTR curQual, double * dimValue,

short inMM, QualityContensParamW * param );

Входные параметры:

HWindow | \- дескриптор окна,  
---|---  
curQual | \- текущее значение квалитета,  
dimValue | \- значение, для которого требуется выбрать квалитет или NULL,  
inMM | \- размерность параметров dimValue, high, low: 1 - миллиметры, 0 - единицы измерения текущего документа.  
  
Выходной параметр:

param | \- указатель на структуру параметров квалитета [QualityContensParamW](structqualitycontensparamw.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае выбора квалитета,  
---|---  
0 | \- в случае отмены выбора или ошибки.  
  
Подразделы:

(отсутствуют)
