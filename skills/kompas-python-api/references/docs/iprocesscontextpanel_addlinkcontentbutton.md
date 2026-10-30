# AddLinkContentButton - Добавить кнопку ссылочного содержимого регистратора

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с контекстной панелью и меню ](ap2038597.html) > [Интерфейс IProcessContextPanel ](iprocesscontextpanel.html) > [IProcessContextPanel - методы ](iprocesscontextpanel_propers.html) |  Scroll [ [ [ ](iprocesscontextpanel_addnewsearchbutton.html "К следующему разделу")](iprocesscontextpanel_propers.html "На уровень выше")](iprocesscontextpanel_addgroupend.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocesscontextpanel.html)

Синтаксис Automation:

BOOL AddLinkContentButton( IPropertyControl * PVal, BSTR Title );

Синтаксис COM:

HRESULT AddLinkContentButton( IPropertyControl * PVal, BSTR Title, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

PVal | \- указатель на интерфейс добавляемого контрола,  
---|---  
Title | \- заголовок.  
  
Подразделы:

(отсутствуют)
