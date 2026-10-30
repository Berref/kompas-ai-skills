# ksGetLibraryStylesArray - Получить указатель на динамический массив стилей

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Функции настройки документа и работы со стилями ](doc_tunes_fncts.html) > [Стили ](doc_styles_fncts.html) |  Scroll [ [ [ ](ksgetlibrarystylesarrayw.html "К следующему разделу")](doc_styles_fncts.html "На уровень выше")](ksdeletestylefromdocument.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetlibrarystylesarray_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksGetLibraryStylesArray](kompasobject_ksgetlibrarystylesarray.html).

Синтаксис:

reference ksGetLibraryStylesArray (char * libraryName,

unsigned char libraryType);

Входные параметры:

libraryName | \- полное имя библиотеки стилей,  
---|---  
libraryType | \- [тип библиотеки стиля](ltypes.html).  
  
Возвращаемое значение:

указатель на динамический массив LIBRARY_STYLE_ARR стилей заданного типа. | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [ksGetLibraryStylesArrayW](ksgetlibrarystylesarrayw.html).

Подразделы:

(отсутствуют)
