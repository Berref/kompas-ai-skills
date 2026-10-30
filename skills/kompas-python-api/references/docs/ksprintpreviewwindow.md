# ksPrintPreviewWindow - Открыть окно предварительного просмотра документа перед печатью

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Функции вывода на печать ](print_docum_fncts.html) |  Scroll [ [ [ ](ksprintkompasdocument.html "К следующему разделу")](print_docum_fncts.html "На уровень выше")](print_docum_fncts.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksprintpreviewwindow_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksPrintPreviewWindow](kompasobject_ksprintpreviewwindow.html).

Синтаксис:

int ksPrintPreviewWindow (reference docsArr, int inquiry);

Входные параметры:

docsArr | \- массив типа CHAR_STR_ARR или CHAR_STR_ARR_W полных имен документов, которые нужно распечатать,  
---|---  
inquiry | \- признак запроса документов: 1 - если docsArr = NULL или массив пуст, запросить документы у пользователя, 0 - показать документы без запроса.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
