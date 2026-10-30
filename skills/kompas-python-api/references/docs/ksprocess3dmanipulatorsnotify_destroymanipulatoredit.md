# DestroyManipulatorEdit - Удаление редактора для ввода значения, управляющего положением манипулятора

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс IProcess3DManipulatorsNotify\ksProcess3DManipulatorsNotify ](ksprocess3dmanipulatorsnotify.html) > [ksProcess3DManipulatorsNotify - методы ](ksprocess3dmanipulatorsnotify_methods.html) |  Scroll [ [ [ ](ksprocess3dmanipulatorsnotify_changemanipulatorvalue.html "К следующему разделу")](ksprocess3dmanipulatorsnotify_methods.html "На уровень выше")](ksprocess3dmanipulatorsnotify_createmanipulatoredit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksprocess3dmanipulatorsnotify.html)

Синтаксис Automation:

BOOL DestroyManipulatorEdit ( long ManipulatorId );

Синтаксис COM:

BOOL DestroyManipulatorEdit ( long ManipulatorId );

Возвращаемое значение:

TRUE | \- если библиотека обработала событие,  
---|---  
FALSE | \- библиотека не обработала событие, требуется использовать встроенную обработку событий манипулятора.  
  
Входные параметры:

ManipulatorId | \- идентификатор манипулятора.  
---|---  
  
Подразделы:

(отсутствуют)
