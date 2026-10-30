# ksNurbsPoint - Создать узел NURBS

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Кривые Безье, NURBS, ломаные ](bt1730148.html) |  Scroll [ [ [ ](ksdocument2d_kspolyline.html "К следующему разделу")](bt1730148.html "На уровень выше")](ksdocument2d_ksnurbsknot.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [NurbsPoint](nurbspoint.html).

Синтаксис Automation:

long ksNurbsPoint (LPDISPATCH param);

Входной параметр:

param | \- указатель на интерфейс [ksNurbsPointParam](ksnurbspointparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Создать очередной узел кривой NURBS. Узлы кривой определяются методами [ksDocument2D::ksPoint](ksdocument2d_kspoint.html) или [ksDocument2D::ksNurbsPoint](ksdocument2d_ksnurbspoint.html). Описание кривой завершается методом [ksDocument2D::ksEndObj](ksdocument2d_ksendobj.html), возвращающим указатель на созданную кривую.

Подразделы:

(отсутствуют)
