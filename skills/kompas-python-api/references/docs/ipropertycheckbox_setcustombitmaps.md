# SetCustomBitmaps - Задать значки для различных состояний элемента управления

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyCheckBox ](ipropertycheckbox.html) > [IPropertyCheckBox - методы ](ipropertycheckbox_methods.html) |  Scroll [ [ [ ](ipropertycolor.html "К следующему разделу")](ipropertycheckbox_methods.html "На уровень выше")](ipropertycheckbox_clearvalue.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](ipropertycheckbox.html)

Синтаксис Automation:

void SetCustomBitmaps (const VARIANT& idUnchecked,

const VARIANT& idChecked,

const VARIANT& idIndeterminate,

const VARIANT& hInstance);

Синтаксис COM:

HRESULT SetCustomBitmaps ([in]VARIANT idUnchecked,

[in]VARIANT idChecked,

[in]VARIANT idIndeterminate,

[in]VARIANT hInstance );

Входные параметры:

idUnchecked | \- значок ненажатого состояния,  
---|---  
idChecked | \- битмап нажатого состояния,  
idIndeterminate | \- битмап неопределенного состояния,  
hInstance | \- dll-модуль с ресурсами значков.  
  
Примечание:

1\. Значки могут быть заданы в виде идентификаторов в ресурсе dll-модуля (тип данных long) или в виде полного пути к bmp-файлу значка (тип данных BSTR). Обязательным является задание значка для ненажатого состояния idUnchecked, остальные могут быть не заданы.

2\. Все значения переменных должны быть одного типа (или long или BSTR).

3\. Если значки задаются в виде идентификатора, то обязательно должен быть задан dll-модуль, в ресурсах которого лежат эти значки. Модуль с ресурсами значков hInstance может быть задан в виде HINSTANCE (тип значения long) или полного пути к файлу (тип значения BSTR) dll-модуля.

Подразделы:

(отсутствуют)
