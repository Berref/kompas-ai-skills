# GetObjParam - Получить параметры объекта

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_getobjecttype.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_getmateconstraint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Аналог данного метода при использовании API экспортных функций - [GetObjParam](getobjparam.html).

Синтаксис Automation:

long ksGetObjParam (long reference, LPDISPATCH param, long paramType);

Входные параметры:

reference | \- указатель на объект,  
---|---  
paramType | \- [тип параметров](paramtypes.html),  
param | \- указатель на интерфейс параметров [ksUserParam](ksuserparam.html).  
  
Возвращаемое значение:

[тип объекта](objtypes.html) | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
