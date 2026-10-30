# Segment - Получить сегмент

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IContour ](icontour.html) > [IContour - свойства ](icontour_props.html) |  Scroll [ [ [ ](icontour_tmpobjects.html "К следующему разделу")](icontour_props.html "На уровень выше")](icontour_count.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icontour.html)

Тип данных: указатель на интерфейс [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

Segment = iObject.Segment(Index); | Получить свойство([* ](1.html))  
---|---  
Segment = iObject.GetSegment(Index); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Segment(Index, &Segment ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство позволяет получить интерфейс сегмента контура [IContourSegment](icontoursegment.html).

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
