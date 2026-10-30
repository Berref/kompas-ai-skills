# ExternalInterface - Получить указатель внешнего интерфейса

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibrary ](ilibrary.html) > [ILibrary - методы ](ilibrary_methods.html) > [Интерфейс IProceduresLibrary ](iprocedureslibrary.html) > [IProceduresLibrary - свойства ](iprocedureslibrary_props.html) |  Scroll [ [ [ ](iprocedureslibrary_iconsfont.html "К следующему разделу")](iprocedureslibrary_props.html "На уровень выше")](iprocedureslibrary_executable.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocedureslibrary.html)

Тип данных: Указатель на интерфейс IDispatch

Синтаксис Automation:

ExternalInterface = Object.ExternalInterface | Получить свойство ([* ](1.html))  
---|---  
ExternalInterface = Object.GetExternalInterface() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ExternalInterface( &ExternalInterface ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Addref на выдаваемый интерфейс не выполняется.

3\. Внешний интерфейс можно использовать для обмена данными между двумя приложениями. Первое приложение передает интерфейс при вызове метода [ILibrary::Execute](ilibrary_execute.html).

4\. После выполнения [ILibrary::Execute](ilibrary_execute.html) свойство ExternalInterface возвращает NULL.

Подразделы:

(отсутствуют)
