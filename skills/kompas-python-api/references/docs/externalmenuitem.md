# ExternalMenuItem - Получить строку меню для создания меню в виде строк

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Пример простейшей программы в среде VB, оформленной в виде ActiveX библиотеки КОМПАС ](simple_sample_ax.html) > [Функции ](cr154576.html) |  Scroll [ [ [ ](externalgettoolbarid.html "К следующему разделу")](cr154576.html "На уровень выше")](externalgetimage.html "К предыдущему разделу")  
---|---  
  
[Пример...](externalmenuitem_sample.html)

TAutoString ExternalMenuItem (short number,

short * itemType,

short * command);

Синтаксис Visual Basic:

Public Function ExternalMenuItem (ByVal number As Integer,

itemType As Integer,

command As Integer) As String

Параметры:

number - счетчик строк

itemType - тип строки

(0 - SEPARATOR (разделитель);

1 - MENUITEM (строка с названием пункта меню);

2 - POPUP (начало выпадающего подменю);

3 (или любое другое число) - ENDMENU (конец меню\подменю).

command - номер команды, если itemType = 1,

или -1 во всех остальных случаях

Подразделы:

(отсутствуют)
