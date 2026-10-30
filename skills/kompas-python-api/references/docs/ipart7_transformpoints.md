# TransformPoints - Перевод координат точек присланной детали Part1 в систему координат детали

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_transferobjects.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_transformpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

BOOL TransformPoints( VARIANT * Points, IPart7 * Part1 );

Синтаксис COM:

HRESULT TransformPoints( VARIANT * Points, IPart7 * Part1, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Points | \- массив SAFEARRAY координат точек в системе координат детали Part1,  
---|---  
Part1 | \- указатель на интерфейс детали в системе координат которой заданы точки.  
  
Выходные параметры:

Points | \- массив SAFEARRAY координат точек в системе координат детали.  
---|---  
  
Примечания:

1\. Значения координат изменяются непосредственно в присланном массиве SAFEARRAY.

2\. Тип варианта должен быть VT_ARRAY | VT_R8.

3\. Значения в массиве должны лежать в последовательности x1, y1, z1, x2, y2, z2 ... xn, yn, zn.

Подразделы:

(отсутствуют)
