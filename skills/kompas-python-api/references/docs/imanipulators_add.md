# Add - Создать манипулятор (добавляет контрол в коллекцию)

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Интерфейс IManipulators ](imanipulators.html) > [IManipulators - методы ](imanipulators_methods.html) |  Scroll [ [ [ ](ibasemanipulator.html "К следующему разделу")](imanipulators_methods.html "На уровень выше")](imanipulators_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imanipulators.html)

Синтаксис Automation:

LPDISPATCH Add( ksManipulatorTypeEnum Type );

Синтаксис COM:

HRESULT Add( ksManipulatorTypeEnum Type, IBaseManipulator * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс [IBaseManipulator](ibasemanipulator.html).  
---|---  
  
Входные параметры:

Type | \- Способ разбиения зоны из перечисления [ksManipulatorTypeEnum](ksmanipulatortypeenum.html).  
---|---  
  
Примечания:

Метод позволяет создать новый базовый интерфейс манипулятора.

Подразделы:

(отсутствуют)
