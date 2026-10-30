# ksGetCurrentDocument - Получить указатель на текущий документ

[API экспортных функций](export_function.html) > [Функции работы с файлами документов ](work_with_files_common.html) |  Scroll [ [ [ ](ksgetfullpathfromsystempath.html "К следующему разделу")](work_with_files_common.html "На уровень выше")](ksfilenamecomparew.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetcurrentdocument_example.html)

Синтаксис:

reference ksGetCurrentDocument (unsigned char type);

Входные параметры:

type | \- тип документа: 0 - любой документ, 1 - только графический документ, 2 - только спецификация 3 - объемная модель (деталь или сборка) 4 - текстовый документ.  
---|---  
  
Возвращаемое значение:

указатель на документ | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
