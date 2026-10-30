# ksChoiceFiles - Выдать диалог выбора файлов для открытия

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Работа с файлами ](ag95246.html) |  Scroll [ [ [ ](kschoicefilesw.html "К следующему разделу")](ag95246.html "На уровень выше")](kompasobject_kschoicefileappointeddir.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)..

Аналог данного метода при использовании API экспортных функций - [ksChoiceFiles](kschoicefiles.html).

Синтаксис Automation:

long ksChoiceFiles (BSTR ext,

BSTR filter,

LPDISPATCH p,

BOOL preview);

Входные параметры:

ext | \- расширение имени файла,  
---|---  
filter | \- фильтр поиска (0 - формируется автоматически),  
preview | \- признак подключения окна предварительного просмотра: 1 - с подключением окна, 0 - без подключения окна.  
  
Выходной параметр:

p | \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) типа CHAR_STR_ARR.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
