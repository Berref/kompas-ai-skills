# ClickManipulatorPrimitive - Клик или двойной клик по примитиву манипулятора

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс IProcess3DManipulatorsNotify\ksProcess3DManipulatorsNotify ](ksprocess3dmanipulatorsnotify.html) > [ksProcess3DManipulatorsNotify - методы ](ksprocess3dmanipulatorsnotify_methods.html) |  Scroll [ [ [ ](ksprocess3dmanipulatorsnotify_begindragmanipulator.html "К следующему разделу")](ksprocess3dmanipulatorsnotify_methods.html "На уровень выше")](ksprocess3dmanipulatorsnotify_movemanipulator.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksprocess3dmanipulatorsnotify.html)

Синтаксис Automation:

BOOL ClickManipulatorPrimitive( long ManipulatorId, ksManipulatorPrimitiveEnum PrimitiveType, BOOL DoubleClick );

Синтаксис COM:

BOOL ClickManipulatorPrimitive( long ManipulatorId, ksManipulatorPrimitiveEnum PrimitiveType, [in] VARIANT_BOOL DoubleClick );

Возвращаемое значение:

TRUE | \- если библиотека обработала событие,  
---|---  
FALSE | \- библиотека не обработала событие, требуется использовать встроенную обработку событий манипулятора.  
  
Входные параметры:

ManipulatorId | \- идентификатор манипулятора,  
---|---  
PrimitiveType | \- примитив манипулятора из перечисления [ksManipulatorPrimitiveEnum](ksmanipulatorprimitiveenum.html),  
DoubleClick | \- двойной клик.  
  
Подразделы:

(отсутствуют)
