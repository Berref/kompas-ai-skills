# ksSaveFile - Выдать диалог выбора файла для сохранения

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Работа с файлами ](ag95246.html) |  Scroll [ [ [ ](ag92071.html "К следующему разделу")](ag95246.html "На уровень выше")](kschoicefilesw.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Аналог данного метода при использовании API экспортных функций - [ksSaveFile](kssavefile.html).

Синтаксис Automation:

BSTR ksSaveFile (BSTR ext,

BSTR oldName,

BSTR filter,

BOOL preview);

Входные параметры:

ext | \- расширение имени файла,  
---|---  
oldName | \- имя файла по умолчанию,  
filter | \- фильтр поиска (0 - формируется автоматически),  
preview | \- признак подключения окна предварительного просмотра: 1 - с подключением окна, 0 - без подключения окна.  
  
Возвращаемое значение:

| \- строка с именем файла.  
---|---  
  
Подразделы:

(отсутствуют)
