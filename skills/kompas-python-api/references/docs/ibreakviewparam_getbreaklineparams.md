# GetBreakLineParams - Получить параметры линии разрыва

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Параметры ](bb2370796.html) > [Интерфейс IBreakViewParam ](ibreakviewparam.html) > [IBreakViewParam - методы ](ibreakviewparam_methods.html) |  Scroll [ [ [ ](ibreakviewparam_getbreaklineposition.html "К следующему разделу")](ibreakviewparam_methods.html "На уровень выше")](ibreakviewparam_deleteallbreaklines.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibreakviewparam.html)

Синтаксис Automation:

BOOL SetBreakLineParams( long Index,

double Angle,

double Clearance,

long BreakLineType,

double Amplitude,

double MaxAmplitude )

Синтаксис COM:

HRESULT SetBreakLineParams( long Index,

double Angle,

double Clearance,

ksBreakLineTypeEnum BreakLineType,

double Amplitude,

double MaxAmplitude,

BOOL * Result );

Входные параметры:

Index | \- индекс линии разрыва,  
---|---  
  
Выходные параметры:

Angle | \- угол, кратный 90 градусам,  
---|---  
Clearance | \- зазор,  
BreakLineType | \- тип линии разрыва,  
Amplitude | \- амплитуда,  
MaxAmplitude | \- максимальная амплитуда.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получать параметры границ разрыва.

Подразделы:

(отсутствуют)
