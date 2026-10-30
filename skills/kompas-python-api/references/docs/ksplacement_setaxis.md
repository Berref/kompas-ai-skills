# SetAxis - Установить компоненты вектора направления оси OX, OY или OZ локальной системы координат

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [Положение объекта (Интерфейсы ksPlacement, IPlacement) ](ksplacement.html) > [IPlacement - методы ](ksplacement_methods.html) |  Scroll [ [ [ ](ksplacement_setorigin.html "К следующему разделу")](ksplacement_methods.html "На уровень выше")](ksplacement_setaxes.html "К предыдущему разделу")  
---|---  
  
[Пример...](placement_example1.html)

[Интерфейс...](ksplacement.html)

Синтаксис Automation:

BOOL SetAxis (double x,

double y,

double z,

long type);

Синтаксис COM:

BOOL SetAxis (double x,

double y,

double z,

int type);

Входные параметры:

x, y, z | \- компоненты вектора направления оси,  
---|---  
type | \- тип оси: 0 – OX, >0 – OY.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
