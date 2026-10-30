# ksGetObjParam - Получить параметры объекта

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Параметры ](bt1730186.html) |  Scroll [ [ [ ](ksdocument2d_kssetobjparam.html "К следующему разделу")](bt1730186.html "На уровень выше")](bt1730186.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [GetObjParam](getobjparam.html).

Синтаксис Automation:

long ksGetObjParam (long reference,

LPDISPATCH param,

long paramType);

Входной параметр:

reference | \- указатель на объект.  
---|---  
  
Выходные параметры:

param | \- указатель на интерфейс параметров,  
---|---  
paramType | \- тип параметров объекта или номер страницы (габаритного прямоугольника) технических требований (TECHNICALDEMAND_OBJ).  
  
[Типы объектов и интерфейсы...](objtypes.html)

[Типы параметров объектов...](paramtypes.html)

Возвращаемое значение:

тип объекта | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Вызов метода с нулевыми значениями параметров param и parType позволяет получить тип объекта по его reference.

Подразделы:

(отсутствуют)
