# Add - Создать элемент управления

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyToolBar ](ipropertytoolbar.html) > [Интерфейс IPropertyControls ](ipropertycontrols.html) > [IPropertyControls - методы ](ipropertycontrols_methods.html) |  Scroll [ [ [ ](ipropertycontrols_delete.html "К следующему разделу")](ipropertycontrols_methods.html "На уровень выше")](ipropertycontrols_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertycontrols.html)

Синтаксис Automation:

LPDISPATCH Add (ControlTypeEnum type);

Синтаксис COM:

HRESULT Add ([in] ControlTypeEnum Type, [out, retval] IPropertyControl** Result);

Входные параметры:

type | \- тип элемента управления из [ControlTypeEnum](controltypeenum.html).  
---|---  
  
Возвращаемое значение:

Указатель на интерфейс [IPropertyControl](ipropertycontrol.html) |   
---|---  
  
Примечание:

Добавляет элемент управления в коллекцию.

Подразделы:

(отсутствуют)
