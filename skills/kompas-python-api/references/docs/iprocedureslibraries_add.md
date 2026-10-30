# Add - Добавить элемент в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс IProceduresLibraries ](iprocedureslibraries.html) > [IProceduresLibraries - методы ](iprocedureslibraries_methods.html) |  Scroll [ [ [ ](adjstment.html "К следующему разделу")](iprocedureslibraries_methods.html "На уровень выше")](iprocedureslibraries_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocedureslibraries.html)

Синтаксис Automation:

LPDISPATCH Add( LPCTSTR PathName, LPCTSTR LibManagerFolder );

Синтаксис COM:

HRESULT Add( BSTR PathName, BSTR LibManagerFolder, IProceduresLibrary** Result);

Входные параметры:

PathName | \- путь к библиотеке документов,  
---|---  
LibManagerFolder | \- раздел в менеджере библиотек.  
  
Возвращаемое значение:

| \- указатель на интерфейс библиотеки документов [IProceduresLibrary](iprocedureslibrary.html), библиотека регистрируется в менеджере библиотек (В V17 Конфигуратор).  
---|---  
  
Подразделы:

(отсутствуют)
