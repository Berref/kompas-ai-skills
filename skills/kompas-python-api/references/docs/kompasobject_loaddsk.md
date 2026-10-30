# LoadDSK - Загрузить dsk КОМПАС

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_quit.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksviewgetdensityandmaterial.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Синтаксис Automation:

BOOL LoadDSK();

Возвращаемое значение:

TRUE | \- в случае удачного открытия dsk,  
---|---  
FALSE | dsk не открыт, возможно открыт ранее.  
  
Примечание:

При открытии dsk будут подгружены документы и библиотеки, которые были подключены в последнем сеансе работы КОМПАС.

Подразделы:

(отсутствуют)
