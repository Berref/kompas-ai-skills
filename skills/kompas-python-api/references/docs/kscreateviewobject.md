# ksCreateViewObject - Создать объект, используя визуальный процесс

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](ksellipse.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](ksconicarc.html "К предыдущему разделу")  
---|---  
  
[Пример...](kscreateviewobject_kseditviewobject_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksCreateViewObject](ksdocument2d_kscreateviewobject.html).

Синтаксис:

reference ksCreateViewObject (unsigned short int type);

Входной параметр:

type | \- тип объекта (см. ltdefine.h LINESEG_OBJ...ORDINATEDIMENSION_OBJ).  
---|---  
  
Возвращаемое значение:

| \- указатель на созданный объект.  
---|---  
  
Примечание:

Функция распространяется на все объекты вида, кроме:

LAYER_OBJ | \- слой,  
---|---  
CONTOUR_OBJ | \- контур,  
MACRO_OBJ | \- нетипизированный макроэлемент,  
FRAGMENT_OBJ | \- вставной фрагмент,  
ELLIPSE_ARC_OBJ | \- дуга эллипса.  
  
Подразделы:

(отсутствуют)
