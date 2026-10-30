# ExternalRunCommand - Выполнить команду библиотеки

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс ksKompasLibrary ](kskompaslibrary.html) > [ksKompasLibrary - методы ](kskompaslibrary_methods.html) |  Scroll [ [ [ ](kskompaslibrary_isonapplication7.html "К следующему разделу")](kskompaslibrary_methods.html "На уровень выше")](kskompaslibrary_externalmenuitem.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompaslibrary.html)

Синтаксис:

void ExternalRunCommand([in]short command, [in]short mode, LPDISPATCH ApplicationInterface );

Входные параметры:

command | \- номер команды приложения,  
---|---  
mode | \- признак деморежима: \- 0 - обычный режим, \- 1 - вызов из дистрибутивной задачи в деморежиме, \- 2 - вызов из демоверсии;  
ApplicationInterface | \- Указатель на интерфейс приложения Компас 3D.  
  
Примечание:

Параметр ApplicationInterface может быть указателем на интерфейс [IApplication](iapplication.html), если реализован метод [ksKompasLibrary::IsOnApplication7](kskompaslibrary_isonapplication7.html), и этот метод вернул значение TRUE, т.е. библиотека работает на API версии 7. Во всех остальных случаях параметр ApplicationInterface будет указателем на интерфейс [KompasObject](kompasobject.html).

Подразделы:

(отсутствуют)
