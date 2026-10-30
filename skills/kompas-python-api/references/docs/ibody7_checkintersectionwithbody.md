# CheckIntersectionWithBody - Проверка наличия пересечений с другим телом

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Твердое тело ](bc2297187.html) > [Интерфейс IBody7 ](ibody7.html) > [IBody7 - методы ](ibody7_methods.html) |  Scroll [ [ [ ](ibody7_checkintersectionwithbodyex.html "К следующему разделу")](ibody7_methods.html "На уровень выше")](ibody7_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibody7.html)

Синтаксис Automation:

VARIANT CheckIntersectionWithBody( IBody7 * OtherBody, BOOL checkTangent );

Синтаксис COM:

HRESULT CheckIntersectionWithBody( IBody7 * OtherBody, BOOL checkTangent, VARIANT * Result );

Возвращаемое значение:

| \- массив результатов пересечения из пересечения [Intersection_Type](intersection_type.html).  
---|---  
  
Входные параметры:

OtherBody | \- тело, с которым проверяется пересечение,  
---|---  
checkTangent | \- считать касания пересечениями.  
  
Версия Компас v23

Подразделы:

(отсутствуют)
