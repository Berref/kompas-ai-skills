# ksChoiceFileAppointedDir - Выдать папку и выбрать имя файла для открытия

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Работа с файлами ](ag95246.html) |  Scroll [ [ [ ](kompasobject_kschoicefiles.html "К следующему разделу")](ag95246.html "На уровень выше")](kompasobject_kschoicefile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Аналог данного метода при использовании API экспортных функций - [ksChoiceFileAppointedDir](kschoicefileappointeddir.html).

Синтаксис Automation:

BSTR ksChoiceFileAppointedDir (BSTR ext,

BSTR filter,

BOOL preview,

long typeDir);

Входные параметры:

ext | \- расширение имени файла,  
---|---  
filter | \- фильтр поиска (0 - формируется автоматически),  
preview | \- признак подключения окна предварительного просмотра: 1 - с подключением окна, 0 - без подключения окна,  
typeDir | [стартовая папка.](foldertypes.html)  
  
Возвращаемое значение:

| \- строка с именем файла.  
---|---  
  
Примечание.

Параметр typeDir может иметь значения sptSYSTEM_FILES и sptLIBS_FILES; во всех остальных случаях открывается текущая папка.

Подразделы:

(отсутствуют)
