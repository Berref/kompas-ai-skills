# ksSetLightObjType - Установить тип подсветки объекта (light=1 - красный) или (light=0 - зеленый)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Навигация по графическому документу ](cm1745694.html) > [Функции навигации ](navigation_fncts.html) |  Scroll [ [ [ ](ksgetobjectsnamebytype.html "К следующему разделу")](navigation_fncts.html "На уровень выше")](ksshowhidetmpobj.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksSetLightObjType](ksdocument2d_kssetlightobjtype.html).

Синтаксис:

int LIB_FUNC ksSetLightObjType( reference ref,

unsigned char light );

Входные параметры:

ref | \- указатель на объект,  
---|---  
light | \- light - (light=1 - красный) или (light=0 - зеленый).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
