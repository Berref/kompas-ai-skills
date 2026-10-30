# Enable - Признак лицензионной защиты библиотеки

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibrary ](ilibrary.html) > [ILibrary - свойства ](ilibrary_props.html) |  Scroll [ [ [ ](ilibrary_librarymanagerfolder.html "К следующему разделу")](ilibrary_props.html "На уровень выше")](ilibrary_attach.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibrary.html)

Тип данных: BOOL

Синтаксис Automation:

Enable = iObject.Enable | Получить свойство ([* ](1.html))  
---|---  
Enable = iObject.GetEnable() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Enable( &Enable ) | Получить свойство  
---|---  
  
Значения свойства:

TRUE | \- библиотека доступна для выполнения или вставки,  
---|---  
FALSE | \- библиотека недоступна для выполнения или вставки.  
  
Примечание:

Свойство возвращает признак лицензионной защиты библиотеки. Библиотека может быть не подключена.

Подразделы:

(отсутствуют)
