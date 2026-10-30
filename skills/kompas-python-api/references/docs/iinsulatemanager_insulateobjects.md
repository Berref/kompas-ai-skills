# InsulateObjects - Получить список изолированных объектов

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Изолирование компонентов](isolation.html) > [Интерфейс IInsulateManager](iinsulatemanager.html) > [IInsulateManager - свойства](iinsulatemanager_propers.html) |  Scroll [ [ [ ](iinsulatemanager_methods.html "К следующему разделу")](iinsulatemanager_propers.html "На уровень выше")](iinsulatemanager_isinsulatemode.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinsulatemanager.html)

Тип данных: BOOL

Синтаксис Automation:

InsulateObjects = Object.InsulateObjects | Получить свойство ([* ](1.html))  
---|---  
InsulateObjects = Object.GetInsulateObjects() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_InsulateObjects( &InsulateObjects ) | Получить свойство  
---|---  
  
Примечание:

1.Свойство доступно только для чтения.

2.Метод возвращает список изолируемых объектов в виде массива SAFEARRAY'я DISPATCH - VT_ARRAY | VT_DISPATCH.

Подразделы:
