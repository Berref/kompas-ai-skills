# ExternalRunCommand - Головная функция библиотеки

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Пример простейшей программы в среде VB, оформленной в виде ActiveX библиотеки КОМПАС ](simple_sample_ax.html) > [Функции ](cr154576.html) |  Scroll [ [ [ ](libinterfacenotifyentry_.html "К следующему разделу")](cr154576.html "На уровень выше")](getimagewidth.html "К предыдущему разделу")  
---|---  
  
void ExternalRunCommand (short command,

short mode,

IDispatch* kompas);

Синтаксис Visual Basic:

Public Sub ExternalRunCommand (ByVal command As Integer,

ByVal mode As Integer,

ByVal kompas_ As Object)

Входные параметры:

command | \- номер выполняемой команды;  
---|---  
mode | \- режим работы: 0 - normal - обычный режим, 1 - demo - вызов из дистрибутивной задачи в деморежиме, 2 - demoEx - вызов из демоверсии;  
kompas | \- интерфейс [KompasObject](kompasobject.html) или [IApplication.](iapplication.html)  
  
Примечание:

1\. При вызове команды библиотеки из меню, панели инструментов или при редактировании библиотечного элемента по двойному нажатию кнопки мыши управление передается этому методу с номером выбранной команды.

2\. Библиотека должна обязательно содержать один из предопределенных методов ExternalRunCommand, который определяет точку входа в приложение или [LibInterfaceNotifyEntry](libinterfacenotifyentry.html). Наличие хотя бы одного из этих методов позволяет системе КОМПАС идентифицировать произвольный ActiveX DLL как собственное приложение.

3\. Параметр kompas может быть указателем на интерфейс [IApplication](iapplication.html), если в библиотеке есть метод [IsOnApplication7](isonapplication7.html), и этот метод вернул значение TRUE, т.е. библиотека работает на API версии 7. Во всех остальных случаях параметр kompas будет указателем на интерфейс [KompasObject](kompasobject.html).

Подразделы:

(отсутствуют)
