# AddButton - Добавить кнопку

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyMultiButton ](ipropertymultibutton.html) > [IPropertyMultiButton - методы ](ipropertymultibutton_methods.html) |  Scroll [ [ [ ](ipropertymultibutton_nextcommand.html "К следующему разделу")](ipropertymultibutton_methods.html "На уровень выше")](ipropertymultibutton_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymultibutton.html)

Синтаксис Automation:

void AddButton (long btnID, const VARIANT& bmp, long insertAt);

Синтаксис COM:

HRESULT AddButton ([in] long btnID, [in] VARIANT bmp, [in, defaultvalue (-1)] long insertAt);

Входные параметры:

btnID | \- идентификатор добавляемой кнопки,  
---|---  
bmp | \- идентификатор значка в файле ресурсов (тип данных long) или полный путь к bmp-файлу значка (тип данных BSTR),  
insertAt | \- индекс кнопки, перед которой нужно вставить добавляемую (-1 - в конец).  
  
Примечание:

Если значок задается в виде идентификатора, то до этого должен быть задан dll-модуль, в ресурсах которого лежит этот значок. Если кнопка с заданным идентификатором уже есть в списке, то ничего добавляться не будет.

Подразделы:

(отсутствуют)
