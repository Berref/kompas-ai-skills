# ksGetSysOptions - Получить системные настройки

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Функции настройки документа и работы со стилями ](doc_tunes_fncts.html) > [Настройки документов ](doc_set_fncts.html) |  Scroll [ [ [ ](ksgetworkwindowcolor.html "К следующему разделу")](doc_set_fncts.html "На уровень выше")](doc_set_fncts.html "К предыдущему разделу")  
---|---  
  
[Пример...](kssetgetsysoptions_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksGetSysOptions](kompasobject_ksgetsysoptions.html).

Синтаксис:

int ksGetSysOptions (int optionsType, void * param, int sizePar);

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

См. также функции:

[GetDocOptions](getdocoptions.html) \- Получить настройки документа,

[SetDocOptions](setdocoptions.html) \- Заменить настройки документа.

Подразделы:

(отсутствуют)
