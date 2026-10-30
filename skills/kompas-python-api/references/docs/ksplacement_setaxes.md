# SetAxes - Установить оси X и Y

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [Положение объекта (Интерфейсы ksPlacement, IPlacement) ](ksplacement.html) > [IPlacement - методы ](ksplacement_methods.html) |  Scroll [ [ [ ](ksplacement_setaxis.html "К следующему разделу")](ksplacement_methods.html "На уровень выше")](ksplacement_rotate.html "К предыдущему разделу")  
---|---  
  
[Пример...](placement_example1.html)

[Интерфейс...](ksplacement.html)

Синтаксис Automation:

VARIANT_BOOL SetAxes (double Xx,

double Xy,

double Xz,

double Yx,

double Yy,

double Yz );

Синтаксис COM:

BOOL SetAxes (double Xx,

double Xy,

double Xz,

double Yx,

double Yy,

double Yz)

Входные параметры:

Xx, Xy, Xz | \- координаты точки на оси X,  
---|---  
Yx, Yy, Yz | \- координаты точки на оси Y.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
