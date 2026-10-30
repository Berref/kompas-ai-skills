# ksUniqueFileName - Получить уникальное имя файла

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Сервисные функции ](ag92071.html) |  Scroll [ [ [ ](kompasobject_transferinterface.html "К следующему разделу")](ag92071.html "На уровень выше")](kompasobject_kssystempath.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Аналог данного метода при использовании API экспортных функций - [UniqueFileName](uniquefilename.html).

Синтаксис Automation:

BSTR ksUniqueFileName();

Возвращаемое значение:

| \- строка с именем файла.  
---|---  
  
Примечание:

Получить уникальное имя для создания служебного файла в процессе работы библиотеки. Имя регистрируется и запоминается системой. По окончании работы в случае, если файл с таким именем существует, он будет автоматически удален.

Подразделы:

(отсутствуют)
