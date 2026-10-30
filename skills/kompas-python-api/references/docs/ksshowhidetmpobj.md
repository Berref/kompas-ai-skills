# ksShowHideTmpObj - Скрыть /Показать временный объект в документе

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Навигация по графическому документу ](cm1745694.html) > [Функции навигации ](navigation_fncts.html) |  Scroll [ [ [ ](kssetlightobjtype.html "К следующему разделу")](navigation_fncts.html "На уровень выше")](releasereference.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

int LIB_FUNC ksShowHideTmpObj( reference ref,

int show );

Входные параметры:

ref | \- указатель на объект,  
---|---  
show | \- значение из перечисления [ksShowHideTmpObjTypeEnum](ksshowhidetmpobjtypeenum.html) ksTmpObjHide - скрыть объект, ksTmpObjShow - показать временный объект как обычный объект, ksTmpObjShowPhantom - показать временный объект как фантом.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
