# ksCalcRasterScale - Рассчитать масштаб для вставки растра в прямоугольник заданных габаритов

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_kschangeleader.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_ksassociationviewmatrix3d.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksCalcRasterScale](kscalcrasterscale.html).

Синтаксис Automation:

double ksCalcRasterScale (BSTR fileName, double w, double h);

Входные параметры:

fileName | \- полный путь к файлу растра,  
---|---  
w | \- ширина габаритного прямоугольника,  
h | \- высота габаритного прямоугольника.  
  
Возвращаемое значение:

масштаб для вставки растра в прямоугольник | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
