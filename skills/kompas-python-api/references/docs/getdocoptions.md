# GetDocOptions - Получить настройки документа

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Общие функции ](common_docum_fncts.html) |  Scroll [ [ [ ](setdocoptions.html "К следующему разделу")](common_docum_fncts.html "На уровень выше")](savedocumentexw.html "К предыдущему разделу")  
---|---  
  
[Пример...](getdocoptions_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetDocOptions](ksdocument2d_ksgetdocoptions.html).

Синтаксис:

int GetDocOptions (int optionsType void * param, int sizePar);

Входной параметр:

optionsType | \- [тип настройки](settypes.html),  
---|---  
sizePar | \- размер структуры параметров.  
  
Выходной параметр:

param | \- указатель на структуру параметров.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
[Соответствие входных и выходных параметров...](settypes_getdoc.html)

Примечание:

Функция позволяет получить настройки текущего документа (в настоящее время функция реализована только для настроек размеров) и заполнить ими соответствующую структуру.

Подразделы:

(отсутствуют)
