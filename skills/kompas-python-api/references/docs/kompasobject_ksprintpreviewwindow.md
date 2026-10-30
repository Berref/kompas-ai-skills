# ksPrintPreviewWindow - Открыть окно предварительного просмотра документа перед печатью

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksreaddouble.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksprintkompasdocumentex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksPrintPreviewWindow](ksprintpreviewwindow.html).

Синтаксис Automation:

long ksPrintPreviewWindow (LPDISPATCH docsArr, long inquiry);

Входные параметры:

docsArr | \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) типа CHAR_STR_ARR,  
---|---  
inquiry | \- признак запроса документов: 1 - если docsArr = NULL или массив пуст, запросить документы у пользователя, 0 - показать документы без запроса.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
