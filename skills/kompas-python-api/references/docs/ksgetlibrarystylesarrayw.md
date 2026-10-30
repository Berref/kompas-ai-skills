# ksGetLibraryStylesArrayW - Получить указатель на динамический массив стилей (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Функции настройки документа и работы со стилями ](doc_tunes_fncts.html) > [Стили ](doc_styles_fncts.html) |  Scroll [ [ [ ](ksgetobjectstyle.html "К следующему разделу")](doc_styles_fncts.html "На уровень выше")](ksgetlibrarystylesarray.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksGetLibraryStylesArray](kompasobject_ksgetlibrarystylesarray.html).

Синтаксис:

reference LIB_FUNC ksGetLibraryStylesArrayW (LPWSTR libraryName,

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

При использовании ANSI следует использовать функцию [ksGetLibraryStylesArray](ksgetlibrarystylesarray.html).

Подразделы:

(отсутствуют)
