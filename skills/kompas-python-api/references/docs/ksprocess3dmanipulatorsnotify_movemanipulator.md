# MoveManipulator - Перемещение манипулятора

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс IProcess3DManipulatorsNotify\ksProcess3DManipulatorsNotify ](ksprocess3dmanipulatorsnotify.html) > [ksProcess3DManipulatorsNotify - методы ](ksprocess3dmanipulatorsnotify_methods.html) |  Scroll [ [ [ ](ksprocess3dmanipulatorsnotify_clickmanipulatorprimitive.html "К следующему разделу")](ksprocess3dmanipulatorsnotify_methods.html "На уровень выше")](ksprocess3dmanipulatorsnotify_rotatemanipulator.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksprocess3dmanipulatorsnotify.html)

Синтаксис Automation:

BOOL MoveManipulator( long ManipulatorId, double VX, double VY, double VZ, double Delta, BOOL FromEdit );

Синтаксис COM:

HRESULT MoveManipulator( long ManipulatorId, double VX, double VY, double VZ, double Delta, BOOL FromEdit, BOOL * Result );

Возвращаемое значение:

TRUE | \- если библиотека обработала событие,  
---|---  
FALSE | \- библиотека не обработала событие, требуется использовать встроенную обработку событий манипулятора (при этом положение фантома процесса не изменится).  
  
Входные параметры:

ManipulatorId | \- идентификатор манипулятора,  
---|---  
VX | \- первая компонента вектора движения,  
VY | \- вторая компонента вектора движения,  
VZ | \- третья компонента вектора движения,  
Delta | \- значение сдвига по вектору движения,  
FromEdit | \- признак поворота с помощью редактора.  
  
Подразделы:

(отсутствуют)
