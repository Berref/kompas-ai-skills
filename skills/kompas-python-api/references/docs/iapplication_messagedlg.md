# MessageDlg - Выдать модельное сообщение

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Интерфейс IApplication ](iapplication.html) > [IApplication - методы ](iapplication_methods.html) |  Scroll [ [ [ ](iapplication_pumpwaitingmessages.html "К следующему разделу")](iapplication_methods.html "На уровень выше")](iapplication_messageboxex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplication.html)

Синтаксис Automation:

long MessageDlg( OLE_HANDLE Parent, BSTR Text, BSTR Caption, BSTR Explanation, long Flags, BSTR PositiveButton, BSTR NegativeButton, BSTR CancelButton, long HelpId, BSTR HelpFileName );

Синтаксис COM:

HRESULT MessageDlg( OLE_HANDLE Parent, BSTR Text, BSTR Caption, BSTR Explanation, long Flags, BSTR PositiveButton, BSTR NegativeButton, BSTR CancelButton, long HelpId, BSTR HelpFileName, long * Result );

Возвращаемое значение:

| \- идентификатор нажатой в диалоге кнопки.  
---|---  
  
Входные параметры:

Parent | \- дескриптор родительского окна,  
---|---  
Text | \- текст сообщения,  
Caption | \- заголовок,  
Explanation | \- дополнительный текст сообщения,  
Flags | \- флаги,  
PositiveButton | \- текст кнопки для позитивного результата,  
NegativeButton | \- текст кнопки для негативного результата,  
CancelButton | \- текст кнопки для отмены,  
HelpId | \- идентификатор справки,  
HelpFileName | \- имя файла справки.  
  
Примечание:

1\. Параметр Flags и возвращаемое значение соответствует аналогичной функции WinApi MessageBox.

2\. Тексты кнопок не обязательные параметры.

3\. Если тексты не заданы, используются названия кнопок по умолчанию.

4\. Наличие кнопок в диалоге зависит от параметра Flags.

Подразделы:

(отсутствуют)
