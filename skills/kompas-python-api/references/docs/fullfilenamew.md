# FullFileNameW - Получить полное имя файла (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](getrightfilename.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](fullfilename.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksFullFileName](kompasobject_ksfullfilename.html).

Синтаксис:

unsigned int FullFileNameW (LPWSTR oldName, LPWSTR newName, unsigned int sizeBuf);

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

2\. При использовании ANSI следует использовать функцию [FullFileName](fullfilename.html).

Подразделы:

(отсутствуют)
