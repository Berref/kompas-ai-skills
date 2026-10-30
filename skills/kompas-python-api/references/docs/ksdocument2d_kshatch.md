# ksHatch - Создать штриховку

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Графические примитивы ](bt1730616.html) |  Scroll [ [ [ ](ksdocument2d_ksinsertraster.html "К следующему разделу")](bt1730616.html "На уровень выше")](ksdocument2d_ksequidistant.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [HatchEx](hatchex.html).

Синтаксис Automation:

long ksHatch (long style,

double Angle,

double step,

double width,

double x0,

double y0);

Входные параметры:

style | \- стиль штриховки,  
---|---  
angle | \- угол штриховки в градусах,  
step | \- шаг штриховки,  
width | \- ширина полосы штрихования вдоль границы штриховки,  
x0, y0 | \- координаты начальной точки штриховки.  
  
[Системные стили штриховок...](hstyles.html)

Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Все следующие далее до вызова метода [ksDocument2D::ksEndObj](ksdocument2d_ksendobj.html) геометрические примитивы определяют границы штриховки (внешние и внутренние). Порядок определения элементов границы является произвольным. Метод ksDocument2D::ksEndObj возвращает указатель на штриховку.

Подразделы:

(отсутствуют)
