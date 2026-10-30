# ksGetFullPathFromRelativePath - Сформировать полный путь к файлу из заданного пути к задающему файлу и относительного пути к файлу

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Сервисные функции ](ag92071.html) |  Scroll [ [ [ ](kompasobject_ksgetfullpathfromsystempath.html "К следующему разделу")](ag92071.html "На уровень выше")](kompasobject_ksfullfilename.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Аналог данного метода при использовании API экспортных функций - [GetFullPathFromRelativePath](ksgetfullpathfromrelativepath.html).

Синтаксис Automation:

BSTR ksGetFullPathFromRelativePath (BSTR mainFilePath, BSTR relativePath);

Входные параметры:

mainFilePath | \- полный путь к задающему файлу,  
---|---  
relativePath | \- относительный путь к требуемому файлу (без общей с задающим файлом части пути).  
  
Возвращаемое значение:

| \- полный путь к файлу.  
---|---  
  
Подразделы:

(отсутствуют)
