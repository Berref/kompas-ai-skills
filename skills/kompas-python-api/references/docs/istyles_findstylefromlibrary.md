# FindStyleFromLibrary - Возвращает внешний стиль, если он был добавлен из библиотеки

[API интерфейсов. Версия 7](applicate.html) > [Работа со стилями ](be1729661.html) > [Интерфейс IStyles ](istyles.html) > [IStyles - методы ](istyles_methods.html) |  Scroll [ [ [ ](istyle.html "К следующему разделу")](istyles_methods.html "На уровень выше")](istyles_copy.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](istyles.html)

Синтаксис Automation:

LPDISPATCH FindStyleFromLibrary( BSTR LibraryPath, long LibraryStyleId );

Синтаксис COM:

HRESULT FindStyleFromLibrary( BSTR LibraryPath, long LibraryStyleId, IStyle * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс [IStyle](istyle.html)  
---|---  
  
Входные параметры:

LibraryPath | \- имя файла библиотеки стилей,  
---|---  
LibraryStyleId | \- уникальный номер стиля.  
  
Подразделы:

(отсутствуют)
