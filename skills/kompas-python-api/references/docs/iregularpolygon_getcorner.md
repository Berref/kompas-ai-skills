# GetCorner - Получить параметры скругления/усечения угла

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IRegularPolygon ](iregularpolygon.html) > [IRegularPolygon - методы ](iregularpolygon_methods.html) |  Scroll [ [ [ ](iregularpolygon_setcorner.html "К следующему разделу")](iregularpolygon_methods.html "На уровень выше")](iregularpolygon_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iregularpolygon.html)

Синтаксис Automation:

BOOL GetCorner( long Index,

long * Type,

double * L1,

double * L2 );

Синтаксис COM:

HRESULT GetCorner( long Index,

ksCornerTypeEnum * Type,

double * L1,

double * L2,

BOOL* Result );

Входные параметры:

Index | \- индекс угла.  
---|---  
  
Выходные параметры:

Type | \- тип угла из перечисления [ksCornerTypeEnum](kscornertypeenum.html),  
---|---  
L1 | \- длина фаски первого сегмента или радиус скругления,  
L2 | \- длина фаски второго сегмента.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить параметры скругления/усечения угла многоугольника.

Подразделы:

(отсутствуют)
