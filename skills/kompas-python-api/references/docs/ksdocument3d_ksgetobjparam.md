# ksGetObjParam - Получить параметры объекта

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_ksisslavespcopened.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_ksdeleteobj.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Аналог данного метода при использовании API экспортных функций - [GetObjParam](getobjparam.html).

Синтаксис Automation:

long ksGetObjParam (long reference, LPDISPATCH param, long paramType);

Входные параметры:

reference | \- указатель на объект,  
---|---  
paramType | \- [тип параметров объекта](paramtypes.html) или индекс строки в массиве для объектов TECHNICALDEMAND_OBJ и TEXT_OBJ или номер страницы (габаритного прямоугольника) технических требований (TECHNICALDEMAND_OBJ),  
Param | \- указатель на интерфейс параметров [ksUserParam](ksuserparam.html).  
  
Возвращаемое значение:

[Тип объекта](objtypes.html) | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Вызов метода с нулевыми значениями параметров param и parType позволяет получить тип объекта по его reference.

Подразделы:

(отсутствуют)
