# GetDynamicArray - Получить указатель на интерфейс динамического массива ksDynamicArray

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_getfragmentlibrary.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_getattributeobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Синтаксис Automation:

LPDISPATCH GetDynamicArray (long type);

Входной параметр:

type | \- [тип динамического массива](ksdmtypes.html).  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html).  
---|---  
  
BOOL preview,

long typeDir);

Входные параметры:

ext | \- расширение имени файла,  
---|---  
filter | \- фильтр поиска (0 - фильтр формируется автоматически),  
preview | \- признак подключения окна предварительного просмотра: 1 - с подключением окна, 0 - без подключения окна,  
typeDir | \- [стартовая папка](foldertypes.html).  
  
Возвращаемое значение:

| \- строка с именем файла.  
---|---  
  
Примечание:

Параметр typeDir может иметь значения sptSYSTEM_FILES и sptLIBS_FILES; во всех остальных случаях открывается текущая папка.

Подразделы:

(отсутствуют)
