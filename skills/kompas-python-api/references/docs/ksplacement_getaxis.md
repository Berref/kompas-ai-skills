# GetAxis - Получить компоненты вектора направления оси OX, OY или OZ локальной системы координат

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [Положение объекта (Интерфейсы ksPlacement, IPlacement) ](ksplacement.html) > [IPlacement - методы ](ksplacement_methods.html) |  Scroll [ [ [ ](ksplacement_getmatrix.html "К следующему разделу")](ksplacement_methods.html "На уровень выше")](ksplacement_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplacement.html)

Синтаксис Automation:

BOOL GetAxis (double* x,

double* y,

double* z,

long type);

Синтаксис COM:

BOOL GetAxis (double *x,

double *y,

double *z,

long type);

Входной параметр:

type | \- тип оси: 0 – OX, 1– OY, >1– OZ.  
---|---  
  
Выходные параметры:

x, y, z | \- компоненты вектора направления оси.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

Положение начала локальной системы координат можно получить при помощи метода [GetOrigin](ksplacement_getorigin.html).

Подразделы:

(отсутствуют)
