# AddLeftToolButton - Добавить кнопку в левую панель

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IContentDialogParam ](icontentdialogparam.html) > [IContentDialogParam - методы ](icontentdialogparam_methods.html) |  Scroll [ [ [ ](icontentdialogparam_addrighttoolbutton.html "К следующему разделу")](icontentdialogparam_methods.html "На уровень выше")](icontentdialogparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icontentdialogparam.html)

Синтаксис Automation:

BOOL AddLeftToolButton( BSTR Header, BOOL HeaderVisible, long CommandID, long IconId, BSTR IconFont, ButtonTypeEnum ButtonType );

Синтаксис COM:

HRESULT AddLeftToolButton( BSTR Header, BOOL HeaderVisible, long CommandID, long IconId, BSTR IconFont, ButtonTypeEnum ButtonType, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

Header | \- имя кнопки,  
---|---  
HeaderVisible | \- отображать имя кнопки на панели,  
CommandID | \- идентификатор команды,  
IconId | \- идентификатор иконки из шрифта,  
IconFont | \- имя шрифта,  
ButtonType | \- тип кнопки из перечисления [ButtonTypeEnum](buttontypeenum.html).  
  
Подразделы:

(отсутствуют)
