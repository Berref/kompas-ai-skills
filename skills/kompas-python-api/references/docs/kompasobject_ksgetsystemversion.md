# ksGetSystemVersion - Получить номер версии системы

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Сервисные функции ](ag92071.html) |  Scroll [ [ [ ](kompasobject_ksgetsystemprofilestring.html "К следующему разделу")](ag92071.html "На уровень выше")](kompasobject_ksgetrelativepathfromsystempath.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)..

Аналог данного метода при использовании API экспортных функций - [ksGetSystemVersion](ksgetsystemversion.html).

Синтаксис Automation:

long ksGetSystemVersion (long* iMajor,

long* iMinor,

long* iRelease,

long* iBuild);

Выходные параметры:

iMajor | \- старшее слово версии,  
---|---  
iMinor | \- младшее слово версии,  
iRelease | \- номер выпуска внутри одной версии,  
iBuild | \- номер сборки внутри одного выпуска.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Пример:

Для версии 5.4 Release 2 Build 1

iMajor = 5

iMinor = 4

iRelease = 2

iBuild = 1

Примечание:

Любой из указателей может быть равен 0, тогда соответствующее ему значение не выдается.

Подразделы:

(отсутствуют)
