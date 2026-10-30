# ksMakeEncloseContoursEx - Получить указатель на группу объектов, охватывающих заданную точку

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_ksmovepoint.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_ksmakeenclosecontours.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksMakeEncloseContoursEx](ksmakeenclosecontoursex.html).

Синтаксис Automation:

long ksMakeEncloseContoursEx( long gr,

double x,

double y,

BOOL forHatch );

Входные параметры:

gr | \- временная группа или 0, если требуются контуры в текущем виде,  
---|---  
x, y | \- координаты точки внутри охватывающих контуров,  
forHatch | \- признак создания контура для штриховки.  
  
Возвращаемое значение:

указатель на временную группу контуров | \- в случае удачного завершения,  
---|---  
0 | \- если контуров не нашлось или в случае неудачи.  
  
Примечание:

forHatch == 1 - при cоздании контуров для штриховки используются объекты со стилем основная и утолщенная, объекты других стилей не учитываются.

forHatch == 0 - при cоздании контура с использованием любых стилей линий.

Подразделы:

(отсутствуют)
