# AddMenuCommand - Добавить пункт меню

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с контекстной панелью и меню ](ap2038597.html) > [Интерфейс IProcessContextIconMenu ](iprocesscontexticonmenu.html) > [IProcessContextIconMenu - методы ](iprocesscontexticonmenu_methods.html) |  Scroll [ [ [ ](doc.html "К следующему разделу")](iprocesscontexticonmenu_methods.html "На уровень выше")](iprocesscontexticonmenu_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocesscontexticonmenu.html)

Синтаксис Automation:

BOOL AddMenuCommand( long Id, BSTR Title, long Icon, BSTR IconFont );

Синтаксис COM:

HRESULT AddMenuCommand( long Id, BSTR Title, long Icon, BSTR IconFont, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Id | \- идентификатор команды,  
---|---  
Title | \- заголовок,  
Icon | \- идентификатор иконки из шрифта,  
IconFont | \- имя библиотечного шрифта или пустая строка для шрифта Компас.  
  
Подразделы:

(отсутствуют)
