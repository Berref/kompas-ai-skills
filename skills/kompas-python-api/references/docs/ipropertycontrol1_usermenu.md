# UserMenu - Дескриптор пользовательского меню

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl1 ](ipropertycontrol1.html) > [IPropertyControl1 - свойства ](ipropertycontrol1_props.html) |  Scroll [ [ [ ](ipropertycontrol1_metods.html "К следующему разделу")](ipropertycontrol1_props.html "На уровень выше")](ipropertycontrol1_resmodule.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertycontrol1.html)

Тип данных: OLE_HANDLE

Синтаксис Automation:

UserMenu = iObject.UserMenu | Получить свойство ([* ](1.html))  
---|---  
iObject.UserMenu = UserMenu | Установить свойство ([* ](1.html))  
UserMenu = iObject.GetUserMenu() | Получить свойство([**](2.html))  
iObject.SetUserMenu (UserMenu) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_UserMenu (&UserMenu) | Получить свойство  
---|---  
iObject->put_UserMenu (UserMenu) | Установить свойство  
  
Значения свойства:

Дескриптор пользовательского контекстного меню на элементе управления. |   
---|---  
  
Примечание:

Если на элементе управления уже было меню, то в случае задания оно заменяется на пользовательское. Дескриптор должен создаваться в библиотеке и быть валидным до конца процесса. Деструктурироваться дескриптор должен на стороне библиотеки по окончанию процесса. После того как меню вывелось и пользователь выбрал какой-то пункт генерируется новое событие - prUserMenuCommand.

Подразделы:

(отсутствуют)
