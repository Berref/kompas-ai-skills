# ksGetSystemProfileStringW - Получить строку из INI-файла системы или из Registry (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](ksgetsystemversion.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](ksgetsystemprofilestring.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksGetSystemProfileString](kompasobject_ksgetsystemprofilestring.html).

Синтаксис:

int LIB_FUNC ksGetSystemProfileStringW (LPWSTRlpSection,

LPWSTRlpKey,

LPWSTRlpReturnedString,

int iSize);

Выходные параметры:

lpSection | \- имя секции,  
---|---  
lpKey | \- имя ключа,  
lpReturnedString | \- буфер для выходной строки,  
iSize | \- размер буфера.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Пример:

lpSection = "Directories"

lpKey = "Sys"

Результат:

lpReturnedString = "c:\Program Files\Kompas54\Sys"

iSize = 29

Примечание:

1\. Если lpReturnedString = 0 или iSize = 0, то возвращается необходимый размер буфера, иначе - возвращается количество переписанных байт (с учетом завершающего 0).

2\. Если возвращаемое значение = 0, значит секция или ключ не были найдены ни в INI-файле, ни в реестре.

Подразделы:

(отсутствуют)
