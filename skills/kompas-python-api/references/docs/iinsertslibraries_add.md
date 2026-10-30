# Add - Добавить элемент в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс IInsertsLibraries ](iinsertslibraries.html) > [IInsertsLibraries - методы ](iinsertslibraries_methods.html) |  Scroll [ [ [ ](iprocedures.html "К следующему разделу")](iinsertslibraries_methods.html "На уровень выше")](iinsertslibraries_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iinsertslibraries.html)

Синтаксис Automation:

LPDISPATCH Add( LPCTSTR PathName, LPCTSTR LibManagerFolder );

Синтаксис COM:

HRESULT Add( BSTR PathName, BSTR LibManagerFolder, IInsertsLibrary** Result);

Входные параметры:

PathName | \- путь к библиотеке документов,  
---|---  
LibManagerFolder | \- раздел в менеджере библиотек.  
  
Возвращаемое значение:

| \- указатель на интерфейс библиотеки документов [IInsertsLibrary](iinsertslibrary.html), библиотека регистрируется в менеджере библиотек (В V17 Конфигуратор).  
---|---  
  
Подразделы:

(отсутствуют)
