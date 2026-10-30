# ksSetObjParam - Установить параметры объекта

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Параметры ](bt1730186.html) |  Scroll [ [ [ ](bt1730197.html "К следующему разделу")](bt1730186.html "На уровень выше")](ksdocument2d_ksgetobjparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [SetObjParam](setobjparam.html).

Синтаксис Automation:

long ksSetObjParam (long Reference,

LPDISPATCH param,

long paramType);

Входные параметры:

Reference | \- указатель на объект,  
---|---  
param | \- [тип параметров объекта](paramtypes.html) или индекс строки в массиве для объектов TECHNICALDEMAND_OBJ и TEXT_OBJ,  
paramType | \- тип параметров объекта или номер страницы (габаритного прямоугольника) технических требований (TECHNICALDEMAND_OBJ).  
  
[Типы объектов и интерфейсы...](objtypes.html)

Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
