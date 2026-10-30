# RotateManipulator - Вращение манипулятора относительно оси на угол

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс IProcess3DManipulatorsNotify\ksProcess3DManipulatorsNotify ](ksprocess3dmanipulatorsnotify.html) > [ksProcess3DManipulatorsNotify - методы ](ksprocess3dmanipulatorsnotify_methods.html) |  Scroll [ [ [ ](ksprocess3dmanipulatorsnotify_movemanipulator.html "К следующему разделу")](ksprocess3dmanipulatorsnotify_methods.html "На уровень выше")](ksprocess3dmanipulatorsnotify_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksprocess3dmanipulatorsnotify.html)

Синтаксис Automation:

BOOL RotateManipulator( long ManipulatorId, double X0, double Y0, double Z0, double AxisZX, double AxisZXY, double AxisZZ, double Angle, BOOL FromEdit );

Синтаксис COM:

HRESULT RotateManipulator( long ManipulatorId, double X0, double Y0, double Z0, double AxisZX, double AxisZXY, double AxisZZ, double Angle, BOOL FromEdit, BOOL * Result );

Возвращаемое значение:

TRUE | \- если библиотека обработала событие,  
---|---  
FALSE | \- библиотека не обработала событие, требуется использовать встроенную обработку событий манипулятора (при этом положение фантома процесса не изменится).  
  
Входные параметры:

ManipulatorId | \- идентификатор манипулятора,  
---|---  
X0 | \- первая координата точки,  
Y0 | \- вторая координата точки,  
Z0 | \- третья координата точки,  
AxisZX | \- ось X,  
AxisZXY | \- ось Y,  
AxisZZ | \- ось Z,  
Angle | \- угол поворота.  
FromEdit | \- признак поворота с помощью редактора.  
  
Подразделы:

(отсутствуют)
