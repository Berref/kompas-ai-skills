# GetInterface - Получить интерфейс 3D объекта по типу

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_getlastfeature.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_geteditmacroobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

LPDISPATCH GetInterface (long o3dType);

Синтаксис COM:

LPUNKNOWN GetInterface (long o3dType);

Входные параметры:

o3dType | \- тип интерфейса.  
---|---  
  
Возвращаемое значение:

Указатель на заданный интерфейс | \- в случае успеха,  
---|---  
NULL | \- в случае неудачи.  
  
Список интерфейсов, возвращаемых функцией GetInterface и функцией [ksDocument3D::GetInterface](ksdocument3d_getinterface.html).

Подразделы:

(отсутствуют)
