# ksPolyline - Создать ломаную линию

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Кривые Безье, NURBS, ломаные ](bt1730148.html) |  Scroll [ [ [ ](bt1756228.html "К следующему разделу")](bt1730148.html "На уровень выше")](ksdocument2d_ksnurbspoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksPolyline](kspolyline.html).

Синтаксис Automation:

long ksPolyline (long style);

Входной параметр:

style | \- стиль линии.  
---|---  
  
[Системные стили линий...](lstyles.html)

Возвращаемое значение:

указатель на ломаную линию | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Ломаная линия - составной объект. Объекты [ksDocument2D::ksPoint](ksdocument2d_kspoint.html), вводимые между методами [ksDocument2D::ksPolyline](ksdocument2d_kspolyline.html) и [ksDocument2D::ksEndObj](ksdocument2d_ksendobj.html), принадлежат ломаной линии. ksDocument2D::ksEndObj возвращает указатель на ломаную линию.

Подразделы:

(отсутствуют)
