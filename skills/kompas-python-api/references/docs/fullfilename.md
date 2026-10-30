# FullFileName - Получить полное имя файла

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](fullfilenamew.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](choicefile.html "К предыдущему разделу")  
---|---  
  
[Пример...](fullfilename_getrightfilename_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksFullFileName](kompasobject_ksfullfilename.html).

Синтаксис:

unsigned int LIB_FUNC FullFileName (LPSTR oldName, LPSTR newName, unsigned int sizeBuf);

Входные параметры:

oldName | \- буфер для имени файла,  
---|---  
sizeBuf | \- размер буфера для имени файла.  
  
Выходные параметры:

newName | \- буфер для полного имени файла.  
---|---  
  
Возвращаемое значение:

длина имени файла | \- в случае удачного завершения,  
---|---  
NULL | \- в случае отказа от выбора.  
  
Примечание:

1\. Если sizeBuf меньше требуемой длины - newName не формируется.

2\. При использовании Unicode следует использовать функцию [FullFileNameW](fullfilenamew.html).

Подразделы:

(отсутствуют)
