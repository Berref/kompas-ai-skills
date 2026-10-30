# ksRemoveUniqueFile - Удалить уникальный служебный файл

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Сервисные функции ](ag92071.html) |  Scroll [ [ [ ](kompasobject_ksresultnull.html "К следующему разделу")](ag92071.html "На уровень выше")](kompasobject_kspumpwaitingmessages.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [RemoveUniqueFile](removeuniquefile.html).

Синтаксис Automation:

BOOL ksRemoveUniqueFile (BSTR fileName);

Входной параметр:

fileName | \- имя служебного файла.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечание:

Удалить служебный файл с уникальным именем, предварительно полученным с помощью функции [ksUniqueFileName](kompasobject_ksuniquefilename.html).

Подразделы:

(отсутствуют)
