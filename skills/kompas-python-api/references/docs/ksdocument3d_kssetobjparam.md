# ksSetObjParam - Установить параметры объекта

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_loadfromadditionformat.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_ksisslavespcopened.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Аналог данного метода при использовании API экспортных функций - [SetObjParam](setobjparam.html).

Синтаксис Automation:

long ksSetObjParam (long reference, LPDISPATCH param, long paramType);

Входные параметры:

reference | \- указатель на объект,  
---|---  
paramType | \- [тип параметров объекта](paramtypes.html) или индекс строки в массиве для объектов TECHNICALDEMAND_OBJ и TEXT_OBJ или номер страницы (габаритного прямоугольника) технических требований (TECHNICALDEMAND_OBJ),  
Param | \- указатель на интерфейс параметров [ksUserParam](ksuserparam.html).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
