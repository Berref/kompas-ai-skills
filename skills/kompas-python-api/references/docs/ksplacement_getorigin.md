# GetOrigin - Получить координаты начала локальной системы координат

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [Положение объекта (Интерфейсы ksPlacement, IPlacement) ](ksplacement.html) > [IPlacement - методы ](ksplacement_methods.html) |  Scroll [ [ [ ](ksplacement_getvector.html "К следующему разделу")](ksplacement_methods.html "На уровень выше")](ksplacement_getmatrix.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplacement.html)

Синтаксис Automation:

BOOL GetOrigin (double* x,

double* y,

double* z);

Синтаксис COM:

BOOL GetOrigin (double *x,

double *y,

double *z);

Выходные параметры:

x, y, z | \- координаты начала локальной системы координат в глобальной системе координат.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

Направление осей локальной системы координат можно получить при помощи метода [GetAxis](ksplacement_getaxis.html).

Подразделы:

(отсутствуют)
