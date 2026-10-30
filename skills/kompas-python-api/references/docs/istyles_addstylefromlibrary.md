# AddStyleFromLibrary - Добавить стиль из библиотеки

[API интерфейсов. Версия 7](applicate.html) > [Работа со стилями ](be1729661.html) > [Интерфейс IStyles ](istyles.html) > [IStyles - методы ](istyles_methods.html) |  Scroll [ [ [ ](istyles_copy.html "К следующему разделу")](istyles_methods.html "На уровень выше")](istyles_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](istyles.html)

Синтаксис Automation:

LPDISPATCH AddStyleFromLibrary (BSTR LibraryPath, long Id, BOOL External );

Синтаксис COM:

HRESULT AddStyleFromLibrary( BSTR LibraryPath, long Id, BOOL External, IStyle * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс [IStyle](istyle.html)  
---|---  
  
Входные параметры:

LibraryPath | \- имя файла библиотеки стилей,  
---|---  
Id | \- номер стиля в библиотеке,  
External | \- признак внешнего стиля.  
  
Подразделы:

(отсутствуют)
