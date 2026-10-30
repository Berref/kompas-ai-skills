# CheckIntersectionWithBodyEx - Проверка наличия пересечений с другим телом

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Твердое тело ](bc2297187.html) > [Интерфейс IBody7 ](ibody7.html) > [IBody7 - методы ](ibody7_methods.html) |  Scroll [ [ [ ](ibody7_curveintersection.html "К следующему разделу")](ibody7_methods.html "На уровень выше")](ibody7_checkintersectionwithbody.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibody7.html)

Синтаксис Automation:

BOOL CheckIntersectionWithBodyEx( IBody7 * OtherBody, VARIANT * IntersectionFaces1, VARIANT * IntersectionFaces2, VARIANT * ConnectedFaces1, VARIANT * ConnectedFaces2 );

Синтаксис COM:

HRESULT CheckIntersectionWithBodyEx( IBody7 * OtherBody, VARIANT * IntersectionFaces1, VARIANT * IntersectionFaces2, VARIANT * ConnectedFaces1, VARIANT * ConnectedFaces2, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

OtherBody | \- второе тело.  
---|---  
  
Выходные параметры:

IntersectionFaces1 | \- пересекаемые грани первого тела,  
---|---  
IntersectionFaces2 | \- пересекаемые грани второго тела,  
ConnectedFaces1 | \- совпадающие грани первого тела,  
ConnectedFaces2 | \- совпадающие грани второго тела.  
  
Примечание:

Пересекаемые и совпадающие грани возвращаются в VARIANT-е следующим образом:

•Если грань одна, то VARIANT заполняется как VT_DISPATH в автоматизации и VT_UNKNOVN в COM.

•Если граней несколько, то VARIANT заполняется как массив SafeArray типа VT_ARRAY | VT_DISPATH в автоматизации и VT_ARRAY | VT_UNKNOVN в COM.

Количество граней в массивах intersectionFaces1 и intersectionFaces2 совпадают и образуют пары, т.е. грань с индексом i из массива intersectionFaces1 пересекается с гранью i из массива intersectionFaces2.

Одна и та же грань может встречаться в массиве несколько раз, если она пересекается с несколькими гранями.

Так же заполняются и массивы connectedFaces1 и connectedFaces2.

Версия Компас v23

Подразделы:

(отсутствуют)
