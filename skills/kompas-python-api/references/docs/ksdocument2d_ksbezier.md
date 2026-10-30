# ksBezier - Создать кривую Безье

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Кривые Безье, NURBS, ломаные ](bt1730148.html) |  Scroll [ [ [ ](ksdocument2d_ksbezierpoint.html "К следующему разделу")](bt1730148.html "На уровень выше")](ksdocument2d_ksaddpowerform.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [Bezier](bezier.html).

Синтаксис Automation:

long ksBezier (short closed, long style);

Входные параметры:

closed | \- признак замыкания сплайна: 0 - незамкнутый, 1 - замкнутый,  
---|---  
style | стиль линии.  
  
[Системные стили линий...](lstyles.html)

Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Кривая Безье - составной объект. Объекты [ksDocument2D::ksBezierPoint](ksdocument2d_ksbezierpoint.html), вводимые между методами ksDocument2D::ksBezier и [ksDocument2D::ksEndObj](ksdocument2d_ksendobj.html), принадлежат кривой. ksDocument2D::ksEndObj возвращает указатель на кривую Безье.

Подразделы:

(отсутствуют)
