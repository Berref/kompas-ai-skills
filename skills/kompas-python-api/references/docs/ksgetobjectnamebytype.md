# ksGetObjectNameByType - Вернуть имя объекта по его типу

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Навигация по графическому документу ](cm1745694.html) > [Функции навигации ](navigation_fncts.html) |  Scroll [ [ [ ](ksgetobjectnamebytypew.html "К следующему разделу")](navigation_fncts.html "На уровень выше")](ksgetobjectsnamebytypew.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetObjectNameByType](ksdocument2d_ksgetobjectnamebytype.html).

Синтаксис:

int LIB_FUNC ksGetObjectNameByType( int type, char * name, unsigned int bufLen );

Входные параметры:

type | \- тип объекта из перечисления [DrawingObjectTypeEnum](drawingobjecttypeenum.html),  
---|---  
bufLen | \- размер буфера name в символах.  
  
Выходные параметры:

name | \- Строковое имя типа объекта во множественном числе - отрезки, дуги и т.д,  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
