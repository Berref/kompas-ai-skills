# CreateMatrix - Задать матрицу трансформации

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_decomposeobject.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_createhyperlink.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

BOOL CreateMatrix( double X, double Y, double Angle, double ScaleX, double ScaleY );

Синтаксис COM:

HRESULT CreateMatrix( double X, double Y, double Angle, double ScaleX, double ScaleY, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y | \- координаты начала локальной системы координат,  
---|---  
Angle | \- угол наклона системы координат в градусах,  
ScaleX | \- масштаб локальной системы координат по оси Х,  
ScaleY | \- масштаб локальной системы координат по оси Y.  
  
Примечание:

1.Допускается вложение матриц трансформации. В результате вложения действует суммарная матрица, полученная произведением накопленных матриц.

2.Объекты вида, вводимые между операторами [IKompasDocument2D1::CreateMatrix](ikompasdocument2d1_creatematrix.html) и [IKompasDocument2D1::DeleteMatrix](ikompasdocument2d1_deletematrix.html), подвергаются преобразованию по суммарной матрице.

Версия Компас v23

Подразделы:

(отсутствуют)
