# GetObjParam - Получить параметры объекта

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](ksapproximationcurve.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](existobj.html "К предыдущему разделу")  
---|---  
  
[Пример...](getobjparam_setobjparam_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetObjParam](ksdocument2d_ksgetobjparam.html).

Синтаксис:

int GetObjParam (reference ref,

void *param,

int parSize,

int parType);

Входной параметр:

ref | \- указатель на объект,  
---|---  
parType | \- [тип параметров объекта](paramtypes.html) или индекс строки в массиве для объектов TECHNICALDEMAND_OBJ и TEXT_OBJ или номер страницы (габаритного прямоугольника) технических требований (TECHNICALDEMAND_OBJ),  
parSize | \- размер структуры для записи параметров.  
  
Выходные параметры:

param | \- указатель на структуру параметров,  
---|---  
  
Возвращаемое значение:

тип объекта | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
[Типы объектов и интерфейсы...](objtypes.html)

Смотрите также

[SetObjParam](setobjparam.html)

Примечание:

Вызов метода с нулевыми значениями параметров param, parSize и parType позволяет получить тип объекта по его reference.

Подразделы:

(отсутствуют)
