# ksCreateInsertionFragment - Создать вставку фрагмента

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](ag163509.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksconvertlangwindowex2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Синтаксис Automation:

int LIB_FUNC ksCreateInsertionFragment( char * fileName );

Входные параметры:

fileName | \- полное имя файла фрагмента.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачи.  
---|---  
  
Примечание:

Допускается fileName следующего вида: "c:\\_f\gr\lib1.lfr|детали|литье|фланец", где:

•c:\\_f\gr\lib1.lfr - имя файла библиотеки фрагментов,

•|детали|литье|- разделы, подразделы внутри библиотеки фрагментов,

•фланец - имя фрагмента.

Функция запускает процесс вставки фрагмента из файла. Функция не ждет завершения процесса вставки.

Подразделы:

(отсутствуют)
