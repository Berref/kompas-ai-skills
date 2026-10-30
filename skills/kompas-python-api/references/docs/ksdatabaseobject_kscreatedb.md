# ksCreateDB - Создать блок заголовка базы данных

[API интерфейсов. Версия 5](ag57940.html) > [База данных (Интерфейс ksDataBaseObject) ](ksdatabaseobject.html) > [ksDataBaseObject - методы ](ksdatabaseobject_methods.html) |  Scroll [ [ [ ](ksdatabaseobject_ksdeletedb.html "К следующему разделу")](ksdatabaseobject_methods.html "На уровень выше")](ksdatabaseobject_ksconnectdb.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdatabaseobject.html)

Синтаксис Automation:

long ksCreateDB (BSTR typeBD);

Входной параметр:

typeBD | \- тип базы данных: TXT_DB - база данных [текстового формата](loa.html), ODBC_DB - база данных, доступная через интерфейс [ODBC](odbc.html).  
---|---  
  
Возвращаемое значение:

указатель на блок заголовка базы данных | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Функция позволяет открыть БД. Одновременно может быть открыто несколько БД.

Подразделы:

(отсутствуют)
