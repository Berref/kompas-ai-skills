# ksSetSysOptions - Задать системные настройки

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Функции настройки документа и работы со стилями ](doc_tunes_fncts.html) > [Настройки документов ](doc_set_fncts.html) |  Scroll [ [ [ ](doc_styles_fncts.html "К следующему разделу")](doc_set_fncts.html "На уровень выше")](ksgetworkwindowcolor.html "К предыдущему разделу")  
---|---  
  
[Пример...](kssetgetsysoptions_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksSetSysOptions](kompasobject_kssetsysoptions.html).

Синтаксис:

int ksSetSysOptions (int optionsType, void * param, int sizePar);

Входной параметр:

optionsType | \- [тип настройки](settypes.html) (реализовано для привязок),  
---|---  
sizePar | \- размер структуры параметров.  
  
Выходной параметр:

param | \- указатель на структуру параметров.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
