# ksSystemPath - Получить системный путь установленного типа

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](kssystempathw.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](ksstopprogressbar.html "К предыдущему разделу")  
---|---  
  
[Пример...](kssystempath_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksSystemPath](kompasobject_kssystempath.html).

Синтаксис:

int ksSystemPath (char *buff, int bufLen, int pathType);

[Типы системных путей...](foldertypes.html)

Входные параметры:

bufLen | \- длина отведенного буфера для строки пути в символах,  
---|---  
pathType | \- тип системной папки.  
  
Выходные параметры:

*buff | \- строка полного пути (включая завершающий 0).  
---|---  
  
Возвращаемое значение:

| длина строки полного пути.  
---|---  
  
Примечание:

1\. Строка пути не должна завершаться символом '\' (за исключением случая корневой папки устройства - "<drive>:\").

2\. При использовании Unicode следует использовать функцию [ksSystemPathW](kssystempathw.html).

Подразделы:

(отсутствуют)
