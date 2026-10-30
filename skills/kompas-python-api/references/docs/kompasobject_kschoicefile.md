# ksChoiceFile - Показать диалог и выбрать в нем имя файла для чтения

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Работа с файлами ](ag95246.html) |  Scroll [ [ [ ](kompasobject_kschoicefileappointeddir.html "К следующему разделу")](ag95246.html "На уровень выше")](ag95246.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Аналог данного метода при использовании API экспортных функций - [ksChoiceFile](kschoicefile.html).

Синтаксис Automation:

BSTR ksChoiceFile (BSTR ext,

BSTR filter,

BOOL preview);

Входные параметры:

ext | \- расширение имени файла,  
---|---  
filter | \- фильтр поиска (0 - формируется автоматически),  
preview | \- признак подключения окна предварительного просмотра: 1 - с подключением окна, 0 - без подключения окна.  
  
Возвращаемое значение:

строка с именем файла | \- в случае удачного завершения,  
---|---  
NULL | \- в случае отказа от выбора.  
  
Подразделы:

(отсутствуют)
