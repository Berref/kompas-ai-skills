# CreateManipulatorEdit - Создание редактора для ввода значения, управляющего положением манипулятора

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс IProcess3DManipulatorsNotify\ksProcess3DManipulatorsNotify ](ksprocess3dmanipulatorsnotify.html) > [ksProcess3DManipulatorsNotify - методы ](ksprocess3dmanipulatorsnotify_methods.html) |  Scroll [ [ [ ](ksprocess3dmanipulatorsnotify_destroymanipulatoredit.html "К следующему разделу")](ksprocess3dmanipulatorsnotify_methods.html "На уровень выше")](ksprocess3dmanipulatorsnotify_enddragmanipulator.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksprocess3dmanipulatorsnotify.html)

Синтаксис Automation:

BOOL CreateManipulatorEdit ( long ManipulatorId, ksManipulatorPrimitiveEnum PrimitiveType );

Синтаксис COM:

BOOL CreateManipulatorEdit ( long ManipulatorId, ksManipulatorPrimitiveEnum PrimitiveType );

Возвращаемое значение:

TRUE | \- если библиотека обработала событие,  
---|---  
FALSE | \- библиотека не обработала событие, требуется использовать встроенную обработку событий манипулятора.  
  
Входные параметры:

ManipulatorId | \- идентификатор манипулятора,  
---|---  
PrimitiveType | \- примитив манипулятора из перечисления [ksManipulatorPrimitiveEnum](ksmanipulatorprimitiveenum.html),  
  
Подразделы:

(отсутствуют)
