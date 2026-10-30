# LibInterfaceNotifyEntry - Головная функция библиотеки. Подписка на обработку событийот системы

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Пример простейшей программы в среде VB, оформленной в виде ActiveX библиотеки КОМПАС ](simple_sample_ax.html) > [Функции ](cr154576.html) |  Scroll [ [ [ ](externalgetmenu.html "К следующему разделу")](cr154576.html "На уровень выше")](externalruncommand.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

BOOL LibInterfaceNotifyEntry (IDispatch *application);

Входные параметры:

application | \- указатель интерфейса приложения [KompasObject](kompasobject.html),  
---|---  
  
Примечание:

Библиотека должна обязательно содержать один из предопределенных методов [ExternalRunCommand](externalruncommand.html), который определяет точку входа в приложение, или LibInterfaceNotifyEntry. Наличие хотя бы одного из этих методов позволяет системе КОМПАС идентифицировать произвольный ActiveX DLL как собственное приложение.

Подразделы:

(отсутствуют)
