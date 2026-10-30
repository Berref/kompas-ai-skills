# SetImage - Установить изображение

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertySeparator ](ipropertyseparator.html) > [IPropertySeparator - методы ](ipropertyseparator_methods.html) |  Scroll [ [ [ ](ipropertyslidebox.html "К следующему разделу")](ipropertyseparator_methods.html "На уровень выше")](ipropertyseparator_methods.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](ipropertyseparator.html)

Синтаксис Automation:

BOOL SetImage (VARIANT idBmp, VARIANT hInstance);

Синтаксис COM:

HRESULT SetImage ([in]VARIANT idBmp,

[in]VARIANT hInstance,

[out, retval] VARIANT_BOOL* pVal);

Входные параметры:

idBmp | \- идентификатор значка в файле ресурсов (тип данных long) или полный путь к bmp файлу значка (тип данных BSTR),  
---|---  
hInstance | \- HINSTANCE модуля, в котором находится изображение.  
  
Возвращаемое значение:

| Результат выполнения метода.  
---|---  
  
Примечание:

Если значок задается в виде идентификатора, то должен быть задан dll-модуль hInstance, в ресурсах которого лежит этот значок.

Подразделы:

(отсутствуют)
