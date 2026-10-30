# ksGetSystemProfileString - Получить строку из файла инициализации системы или из реестра

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Сервисные функции ](ag92071.html) |  Scroll [ [ [ ](kompasobject_ksisenabletaskaccess.html "К следующему разделу")](ag92071.html "На уровень выше")](kompasobject_ksgetsystemversion.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)..

Аналог данного метода при использовании API экспортных функций - [ksGetSystemProfileString](ksgetsystemprofilestring.html).

Синтаксис Automation:

BSTR ksGetSystemProfileString (BSTR lpSection,

BSTR lpKey);

Входные параметры:

lpSection | \- имя секции,  
---|---  
lpKey | \- имя ключа.  
  
Возвращаемое значение:

строка из файла инициализации системы (kompasw.ini) или из реестра (Registry) | \- в случае успеха,  
---|---  
NULL | \- если секция или ключ не найдены.  
  
Пример:

lpSection = "Directories"

lpKey = "Sys"

Результат: lpReturnedString = "c:\Program Files\Kompas54\Sys"

Подразделы:

(отсутствуют)
