# SetCorner - Установить параметры скругления/усечения угла

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IEquidistant ](iequidistant.html) > [IEquidistant - методы ](iequidistant_methods.html) |  Scroll [ [ [ ](ihatch.html "К следующему разделу")](iequidistant_methods.html "На уровень выше")](iequidistant_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iequidistant.html)

Синтаксис Automation:

BOOL SetCorner( long Index,

long * Type,

double * L1,

double * L2 );

Синтаксис COM:

HRESULT SetCorner( long Index,

ksCornerTypeEnum * Type,

double * L1,

double * L2,

BOOL* Result );

Входные параметры:

Index | \- индекс угла.  
---|---  
Type | \- тип угла из перечисления [ksCornerTypeEnum](kscornertypeenum.html),  
L1 | \- длина фаски первого сегмента или радиус скругления,  
L2 | \- длина фаски второго сегмента.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить параметры скругления/усечения угла многоугольника.

Подразделы:

(отсутствуют)
