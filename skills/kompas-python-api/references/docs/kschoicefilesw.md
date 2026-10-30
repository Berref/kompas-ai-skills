# ksChoiceFilesW - Выдать диалог выбора файлов для чтения (Unicode)

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Работа с файлами ](ag95246.html) |  Scroll [ [ [ ](kompasobject_kssavefile.html "К следующему разделу")](ag95246.html "На уровень выше")](kompasobject_kschoicefiles.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksChoiceFiles](kompasobject_kschoicefiles.html).

Синтаксис:

int LIB_FUNK ksChoiceFileW (LPWSTR ext,

LPWSTR filter,

reference p,

unsigned char preview);

Входные параметры:

ext | \- расширение имени файла,  
---|---  
filter | \- фильтр поиска (0 - формируется автоматически),  
preview | \- признак подключения окна предварительного просмотра: 1 - с подключением окна, 0 - без подключения окна.  
  
Выходной параметр:

p | \- указатель на динамический массив строк CHAR_STR_ARR или CHAR_STR_ARR_W.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании ANSI следует использовать функцию [ksChoiceFiles](kschoicefiles.html).

Подразделы:

(отсутствуют)
