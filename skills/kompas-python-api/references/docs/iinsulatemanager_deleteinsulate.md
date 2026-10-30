# DeleteInsulate - Удалить объект из списка изолированных

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Изолирование компонентов](isolation.html) > [Интерфейс IInsulateManager](iinsulatemanager.html) > [IInsulateManager - методы](iinsulatemanager_methods.html) |  Scroll [ [ [ ](iinsulatemanager_startinsulatemode.html "К следующему разделу")](iinsulatemanager_methods.html "На уровень выше")](iinsulatemanager_addinsulate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinsulatemanager.html)

Синтаксис Automation:

BOOL DeleteInsulate( VARIANT Objects ) ;

Синтаксис COM:

HRESULT DeleteInsulate( VARIANT Objects, BOOL * Result );

Возвращаемое значение:

TRUE | \- успешное завершение,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- Список исключаемых из изоляции объектов в виде массива SAFEARRAY'я DISPATCH - VT_ARRAY | VT_DISPATCH.  
---|---  
  
Подразделы:

(отсутствуют)
