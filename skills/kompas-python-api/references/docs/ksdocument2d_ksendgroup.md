# ksEndGroup - Завершить создание группы

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Группы объектов ](bt1732733.html) |  Scroll [ [ [ ](ksdocument2d_ksexcludeobjgroup.html "К следующему разделу")](bt1732733.html "На уровень выше")](ksdocument2d_kscleargroup.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [EndGroup](endgroup.html).

Синтаксис Automation:

long ksEndGroup();

Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Объекты вида, виды, слои, если они вводились между методами [ksDocument2D::ksNewGroup](ksdocument2d_ksnewgroup.html) и [ksDocument2D::ksEndGroup](ksdocument2d_ksendgroup.html), попадают в группу.

Если группа временная, объекты считаются временными.

Подразделы:

(отсутствуют)
