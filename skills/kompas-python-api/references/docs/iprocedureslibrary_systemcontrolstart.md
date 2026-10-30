# SystemControlStart - Передать управление системе из под библиотеки

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibrary ](ilibrary.html) > [ILibrary - методы ](ilibrary_methods.html) > [Интерфейс IProceduresLibrary ](iprocedureslibrary.html) > [IProceduresLibrary - методы ](iprocedureslibrary_methods.html) |  Scroll [ [ [ ](iprocedureslibrary_systemcontrolstop.html "К следующему разделу")](iprocedureslibrary_methods.html "На уровень выше")](iprocedureslibrary_openhelp.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocedureslibrary.html)

Синтаксис Automation:

ksSystemControlStartEnum SystemControlStart( BSTR menuCommand );

Синтаксис COM:

HRESULT SystemControlStart([in] BSTR menuCommand, [out, retval] ksSystemControlStartEnum* pVal);

Входные параметры:

PathFolder | \- путь к папке,  
---|---  
post | \- TRUE - отложенное выполнение.  
  
Возвращаемое значение:

[ksSystemControlStartEnum](kssystemcontrolstartenum.html) |   
---|---  
  
Примечание:

Библиотечная функция отдает управление КОМПАС-ГРАФИК для интерактивной доработки документа. Возврат в библиотечную функцию будет осуществлен после нажатия команды в меню Библиотеки, обозначенной строкой menuCommand.

Если строка не задана, то ей автоматически будет присвоено значение "Вернуться в библиотеку" (функция вернет ksSCStoppedByMenuCommand). Или при вызове из этой же библиотеки [SystemControlStop](iprocedureslibrary_systemcontrolstop.html) (функция вернет ksSCStopItself). Библиотека, находясь в этом режиме, как бы замирает на вызове SystemControlStart. Если этот режим вызван в другой библиотеке, то в данной библиотеке режим выполняться не будет (функция вернет ksSCStartedByAnotherLibrary). Только одна библиотека может находиться в режиме SystemControlStart.

Подразделы:

(отсутствуют)
