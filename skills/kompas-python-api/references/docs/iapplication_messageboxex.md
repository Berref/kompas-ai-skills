# MessageBoxEx - Выдать всплывающее сообщение

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Интерфейс IApplication ](iapplication.html) > [IApplication - методы ](iapplication_methods.html) |  Scroll [ [ [ ](iapplication_messagedlg.html "К следующему разделу")](iapplication_methods.html "На уровень выше")](iapplication_iskompascommandcheck.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplication.html)

Синтаксис Automation:

long MessageBoxEx( BSTR Text, BSTR Caption, long Flags )

Синтаксис COM:

HRESULT MessageBoxEx( BSTR Text, BSTR Caption, long Flags, long * Result );

Входные параметры:

Text | \- текст сообщения,  
---|---  
Caption | \- заголовок сообщения,  
Flags | \- флаги.  
  
Примечание:

Параметр Flags и возвращаемое значение соответствует аналогичной функции WinApi MessageBox.

Дополнительно функция позволяет выдать всплывающее сообщение если в настройках Компас установлен признак Сервис->Параметры->Система->Общее->Всплывающие сообщения->Использовать всплывающие сообщения вместо информационных диалогов.

Сообщение выдается всплывающим, если используется комбинация флагов MB_OK | MB_ICONINFORMATION или MB_OK | MB_ICONWARNING.

Если установлены какие-либо другие флаги, то сообщение выдается как обычное сообщение типа MessageBox.

Если не задан заголовок сообщения, выдается умолчательный заголовок - «Сообщение библиотеки».

Если не задан текст сообщения, выдается сообщение о текущей ошибке аналогично функции [MessageBoxResult](messageboxresult.html).

Подразделы:

(отсутствуют)
