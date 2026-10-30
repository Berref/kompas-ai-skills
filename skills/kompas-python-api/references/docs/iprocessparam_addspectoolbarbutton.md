# AddSpecToolbarButton - Добавить кнопку в спецпанель

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IProcessParam ](iprocessparam.html) > [IProcessParam - методы ](iprocessparam_methods.html) |  Scroll [ [ [ ](iprocessparam_clearspectoolbar.html "К следующему разделу")](iprocessparam_methods.html "На уровень выше")](iprocessparam_addsetupmenucommand.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocessparam.html)

Синтаксис Automation:

BOOL AddSpecToolbarButton( long BtnID, VARIANT Bmp, BSTR Tips, BSTR IconFont );

Синтаксис COM:

HRESULT AddSpecToolbarButton( long BtnID, VARIANT Bmp, BSTR Tips, BSTR IconFont, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

BtnID | \- идентификатор кнопки,  
---|---  
Bmp | \- идентификатор картинки, или символа шрифта, или путь к файлу,  
ips | \- имя кнопки,  
IconFont | \- имя шрифта.  
  
Примечание:

1\. Для использования иконок из шрифта Компас нужно передать параметр IconFont == пустой строке.

2\. Для использования шрифта библиотеки, описанного в манифесте библиотеки, нужно передать строчку полученную методом [IProceduresLibrary::IconsFont](iprocedureslibrary_iconsfont.html).

3\. Для использования картинок из ресурсов требуется установить свойство [IProcessParam::ResModule](iprocessparam_resmodule.html). Для использования шрифтовых иконок свойство [IProcessParam::ResModule](iprocessparam_resmodule.html) устанавливаться не должно.

Подразделы:

(отсутствуют)
