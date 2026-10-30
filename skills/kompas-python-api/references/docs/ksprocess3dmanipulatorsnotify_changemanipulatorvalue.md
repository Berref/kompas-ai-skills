# ChangeManipulatorValue - Завершение редактирования значения в редакторе манипулятора

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс IProcess3DManipulatorsNotify\ksProcess3DManipulatorsNotify ](ksprocess3dmanipulatorsnotify.html) > [ksProcess3DManipulatorsNotify - методы ](ksprocess3dmanipulatorsnotify_methods.html) |  Scroll [ [ [ ](ksplmobjectnotify.html "К следующему разделу")](ksprocess3dmanipulatorsnotify_methods.html "На уровень выше")](ksprocess3dmanipulatorsnotify_destroymanipulatoredit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksprocess3dmanipulatorsnotify.html)

Синтаксис Automation:

BOOL ChangeManipulatorValue (long ManipulatorId, ksManipulatorPrimitiveEnum PrimitiveType, double newValue );

Синтаксис COM:

BOOL ChangeManipulatorValue (long ManipulatorId, ksManipulatorPrimitiveEnum PrimitiveType, double newValue );

Возвращаемое значение:

TRUE | \- если библиотека обработала событие,  
---|---  
FALSE | \- библиотека не обработала событие, требуется использовать встроенную обработку событий манипулятора.  
  
Входные параметры:

ManipulatorId | \- идентификатор манипулятора,  
---|---  
PrimitiveType | \- примитив манипулятора из перечисления [ksManipulatorPrimitiveEnum](ksmanipulatorprimitiveenum.html),  
newValue | \- новое значение.  
  
Подразделы:

(отсутствуют)
