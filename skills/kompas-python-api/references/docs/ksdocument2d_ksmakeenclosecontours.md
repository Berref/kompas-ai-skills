# ksMakeEncloseContours - Получить указатель на группу объектов, охватывающих заданную точку

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_ksmakeenclosecontoursex.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_kslengthintomtr.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksMakeEncloseContours](ksmakeenclosecontours.html).

Синтаксис Automation:

long ksMakeEncloseContours (long gr,

double x,

double y);

Входные параметры:

gr | \- временная группа или 0, если требуются контуры в текущем виде,  
---|---  
x, y | \- координаты точки внутри охватывающих контуров.  
  
Возвращаемое значение:

указатель на временную группу контуров | \- в случае удачного завершения,  
---|---  
0 | \- если контуров не нашлось или в случае неудачи.  
  
Примечание:

Возвращаемая группа принадлежит указанной временной группе или текущему виду в целом.

Подразделы:

(отсутствуют)
