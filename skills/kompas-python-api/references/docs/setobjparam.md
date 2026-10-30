# SetObjParam - Задать параметры указанного объекта

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](symmetryobj.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](rotateobj.html "К предыдущему разделу")  
---|---  
  
[Пример...](getobjparam_setobjparam_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksSetObjParam](ksdocument2d_kssetobjparam.html) и [ksDocument3D::ksSetObjParam](ksdocument3d_kssetobjparam.html)

Синтаксис:

int SetObjParam (reference ref,

void *param,

int parSize,

int paramType);

Входные параметры:

ref | \- указатель на объект,  
---|---  
parSize | \- размер структуры для записи параметров,  
paramType | \- [тип параметров объекта](paramtypes.html) или индекс строки в массиве для объектов TECHNICALDEMAND_OBJ и TEXT_OBJ или номер страницы (габаритного прямоугольника) технических требований (TECHNICALDEMAND_OBJ).  
  
Выходные параметры:

param | \- указатель на структуру параметров.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
[Типы объектов и интерфейсы...](objtypes.html)

Примечание:

Данная функция позволяет обрабатывать параметры графического объекта (отрезка, размеров и т.п.), вида, слоя.

Смотрите также [GetObjParam](getobjparam.html)

Подразделы:

(отсутствуют)
