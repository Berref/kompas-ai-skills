# TransformPoints - Перевести координаты точек присланной детали part1 в систему координат детали

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_variablecollection.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_transformpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

BOOL TransformPoints( VARIANT * points,

LPDISPATCH part1 );

Синтаксис COM:

BOOL TransformPoints( VARIANT * points,

LPPART part1 );

Входные параметры:

points | \- массив SAFEARRAY координат точек,  
---|---  
part1 | \- указатель на интерфейс детали в системе координат которой заданы точки.  
  
Выходные параметры:

points | \- массив SAFEARRAY координат точек.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечания:

1\. Значения координат изменяются непосредственно в присланном массиве SAFEARRAY.

2\. Тип варианта должен быть VT_ARRAY | VT_R8.

3\. Значения в массиве должны лежать в последовательности x1, y1, z1, x2, y2, z2 ... xn, yn, zn.

Подразделы:

(отсутствуют)
