# AddSpecToolbarButton - Добавить кнопку в спецпанель

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyManager ](ipropertymanager.html) > [IPropertyManager - методы ](ipropertymanager_methods.html) |  Scroll [ [ [ ](ipropertymanager_clearspectoolbar.html "К следующему разделу")](ipropertymanager_methods.html "На уровень выше")](ipropertymanager_addsetupmenucommand.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymanager.html)

Синтаксис Automation:

BOOL AddSpecToolbarButton( long BtnID, VARIANT Bmp, BSTR Tips, BSTR IconFont );

Синтаксис COM:

HRESULT AddSpecToolbarButton( long BtnID, VARIANT Bmp, BSTR Tips, BSTR IconFont, BOOL * Result );

Возвращаемое значение:

TRUE | \- успешное завершение,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

BtnID | \- идентификатор кнопки,  
---|---  
Bmp | \- идентификатор картинки или символа шрифта или путь к файлу,  
Tips | \- имя кнопки,  
IconFont | \- имя шрифта.  
  
Примечание:

1\. Для использования иконок из шрифта Компас нужно передать параметр IconFont == пустой строке.

2\. Для использования шрифта библиотеки, описанного в манифесте библиотеки, нужно передать строчку, полученную методом [IProceduresLibrary::IconsFont](iprocedureslibrary_iconsfont.html).

3\. Для использования картинок из ресурсов требуется установить свойство [IPropertyManager::ResModule](ipropertymanager_resmodule.html).

4\. Для использования шрифтовых иконок свойство [IPropertyManager::ResModule](ipropertymanager_resmodule.html) устанавливаться не должно.

Подразделы:

(отсутствуют)
