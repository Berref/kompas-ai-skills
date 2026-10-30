# AddLine - Добавить линию

[API интерфейсов. Версия 7](applicate.html) > [Работа со стилями ](be1729661.html) > [Интерфейс IHatchStyle ](ihatchstyle.html) > [IHatchStyle - методы ](ihatchstyle_methods.html) |  Scroll [ [ [ ](ihatchstyle_clearlines.html "К следующему разделу")](ihatchstyle_methods.html "На уровень выше")](ihatchstyle_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ihatchstyle.html)

Синтаксис Automation:

BOOL AddLine( ICurveStyle * Style, double X, double Y, double Angle, double DX, double DY );

Синтаксис COM:

HRESULT AddLine( ICurveStyle * Style, double X, double Y, double Angle, double DX, double DY, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
  
Входные параметры:

Style | \- пользовательский стиль кривой [ICurveStyle](icurvestyle.html),  
---|---  
X | \- начальное положение по x относительно базовой точки,  
Y | \- начальное положение по y относительно базовой точки,  
Angle | \- добавочный угол поворота относительно угла штриховки,  
DX | \- смещение по направлению линии,  
DY | \- смещение по нормали к линии.  
  
Подразделы:

(отсутствуют)
