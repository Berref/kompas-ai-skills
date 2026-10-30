# ksGetSystemVersion - Получить версию системы

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](ksgetlibrarystatus.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](ksgetsystemprofilestringw.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetsystemversion_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksGetSystemVersion](kompasobject_ksgetsystemversion.html).

Синтаксис:

void ksGetSystemVersion (int *iMajor, int *iMinor, int *iRelease, int *iBuild);

Выходные параметры:

iMajor | \- старшее слово версии,  
---|---  
iMinor | \- младшее слово версии,  
iRelease | \- номер выпуска внутри одной версии,  
iBuild | \- номер сборки внутри одного выпуска.  
  
Примечание:

Любой из указателей может быть равен 0, тогда соответствующее ему значение не выдается.

Подразделы:

(отсутствуют)
