# ResModule - Модуль с описанием пользовательской спецпанели

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyManager ](ipropertymanager.html) > [IPropertyManager - свойства ](ipropertymanager_props.html) |  Scroll [ [ [ ](ipropertymanager_spectoolbar.html "К следующему разделу")](ipropertymanager_props.html "На уровень выше")](ipropertymanager_propertytabs.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymanager.html)

Тип данных: VARIANT ( LONG_PTR или BSTR).

Синтаксис Automation:

ResModule = Object.ResModule | Получить свойство ([* ](1.html))  
---|---  
Object.ResModule = ResModule | Установить свойство ([* ](1.html))  
ResModule = Object.GetResModule() | Получить свойство([**](2.html))  
Object.SetResModule( ResModule ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ResModule( &ResModule ) | Получить свойство  
---|---  
Object.put_ResModule( ResModule ) | Установить свойство  
  
Значение свойства:

HINSTANCE (тип значения LONG_PTR) | \- полный путь к файлу (тип значения BSTR) dll-модуля, в котором находятся все необходимые ресурсы.  
---|---  
  
Примечание:

1\. HINSTANCE библиотеки нужно передать через VARIANT, как VT_I4 в Win32 и VT_I8 в x64.

Для правильного формирования _variant_t HINSTANCE нужно передавать через приведение к (LONG_PTR).

2\. Данное свойство позволяет установить или получить dll-модуль, в котором находится описание пользовательской спецпанели, (пример для пользовательских кнопок см. [IPropertyManager::SpecToolbarEx](ipropertymanager_spectoolbarex.html)).

3\. Свойство не используется при работе со шрифтовыми иконками

Подразделы:

(отсутствуют)
