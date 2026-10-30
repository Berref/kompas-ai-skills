# ExternalMenuItem - Динамическая накачка меню

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс ksKompasLibrary ](kskompaslibrary.html) > [ksKompasLibrary - методы ](kskompaslibrary_methods.html) |  Scroll [ [ [ ](kskompaslibrary_externalruncommand.html "К следующему разделу")](kskompaslibrary_methods.html "На уровень выше")](kskompaslibrary_getprotectnumber.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompaslibrary.html)

Синтаксис:

BSTR ExternalMenuItem( [in] short Index, [out]short * ItemType, [out] short * Command );

Входные параметры:

Index | \- индекс пункта меню.  
---|---  
  
Выходные параметры:

itemType | \- тип пункта меню: \- 0 - SEPARATOR (разделитель); \- 1 - MENUITEM (строка с названием пункта меню); \- 2 - POPUP (начало выпадающего подменю); \- 3 (или любое другое число) - ENDMENU (конец меню\подменю).  
---|---  
command | \- номер команды, если itemType = 1, или -1 во всех остальных случаях;  
  
Возвращаемое значение

  
| \- текст пункта меню.  
---|---  
  
Подразделы:

(отсутствуют)
