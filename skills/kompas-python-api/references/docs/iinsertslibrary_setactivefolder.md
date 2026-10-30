# SetActiveFolder - Установить активную папку в окне библиотеки элементов (документов)

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ILibrary ](ilibrary.html) > [ILibrary - методы ](ilibrary_methods.html) > [Интерфейс IInsertsLibrary ](iinsertslibrary.html) > [IInsertsLibrary - методы ](iinsertslibrary_methods.html) |  Scroll [ [ [ ](iprocedureslibrary.html "К следующему разделу")](iinsertslibrary_methods.html "На уровень выше")](iinsertslibrary_removefolder.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](iinsertslibrary.html)

Синтаксис Automation:

BOOL SetActiveFolder (BSTR PathFolder, BOOL LastIsFile, BOOL HaveLibName);

Синтаксис COM:

HRESULT SetActiveFolder ([in] BSTR PathFolder,

VARIANT_BOOL LastIsFile,

VARIANT_BOOL HaveLibName,

[out, retval] VARIANT_BOOL * pVal);

Входные параметры:

PathFolder | \- путь к папке,  
---|---  
LastIsFile | TRUE - в пути имеется имя файла документа,  
HaveLibName(BOOL) | \- TRUE - в пути имеется имя библиотеки.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить активную папку в окне библиотеки документов. Путь к папке может содержать или не содержать имя библиотеки и имя документа. Имя библиотеки, имя папки и имя документа разделяются символом "|". Если папка является вложенной, т. е. находится внутри другой папки, названия папок в пути отделяются символом "|".

Пример. Библиотека с именем 111, содержит папку с именем ddd, в которой находится файл с именем fragment. Путь к этому файлу должен быть задан следующим образом: 111|ddd|fragment.

Подразделы:

(отсутствуют)
