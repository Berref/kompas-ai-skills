# ksAnnPolyline - Создать аннотационную ломаную линию

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Аннотационные объекты ](bt1730611.html) |  Scroll [ [ [ ](ksdocument2d_ksannpolylineex.html "К следующему разделу")](bt1730611.html "На уровень выше")](ksdocument2d_ksannpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksAnnPolyline](ksannpolyline.html).

Синтаксис Automation:

long ksAnnPolyline ( long style,

short term1,

short term2 );

Входные параметры:

style | \- [стиль линии,](lstyles.html)  
---|---  
term1, term2 | \- [типы значков](marktypes.html) на концах ломаной.  
  
Возвращаемое значение:

указатель на аннотационную ломаную линию | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Аннотационные объекты можно создавать только в составе макро. ksDocument2D::ksAnnPolyline - составной объект. Объекты ksDocument2D::ksPoint, вводимые между операторами ksDocument2D::ksAnnPolyline и [ksDocument2D::ksEndObj](ksdocument2d_ksendobj.html), принадлежат аннотационной ломаной. Метод ksDocument2D::ksEndObj возвращает указатель на аннотационную ломаную линию. Допускается создание аннотационных объектов во временной группе для последующего добавления в макро.

2\. При разрушении макро аннотационные объекты превращаются в геометрические.

Подразделы:

(отсутствуют)
