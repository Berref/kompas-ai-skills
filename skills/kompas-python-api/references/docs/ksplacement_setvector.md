# SetVector - Задать вектор для указанной оси

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [Положение объекта (Интерфейсы ksPlacement, IPlacement) ](ksplacement.html) > [IPlacement - методы ](ksplacement_methods.html) |  Scroll [ [ [ ](ca1789250.html "К следующему разделу")](ksplacement_methods.html "На уровень выше")](ksplacement_setplacement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplacement.html)

Синтаксис Automation:

BOOL SetVector( long type, double * X, double * Y, double * Z );

Синтаксис COM:

BOOL SetVector( long type, double * X, double * Y, double * Z );

Возвращаемое значение:

TRUE | \- в случае удачи.  
---|---  
  
Входные параметры:

type | \- тип оси: 0 – OX, 1 – OY, >1 – OZ.  
---|---  
  
Выходные параметры:

X, Y, Z | \- компоненты вектора направления оси.  
---|---  
  
Подразделы:

(отсутствуют)
