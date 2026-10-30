# ksGetSpcPerformanceNameW - Получить отображаемое имя исполнения (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcpropertyfill.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcperformancename.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcPerformanceName](ksspecification_ksgetspcperformancename.html).

Синтаксис:

int LIB_FUNC ksGetSpcPerformanceNameW( int index,

int ispoln,

int blockNumber,

LPWSTR name,

int nameLen );

Входные параметры:

index | \- индекс описания СП в документе,  
---|---  
ispoln | \- номер колонки типа "количество", начиная с 1(актуально для СП типа Б),  
blockNumber | \- номер блока, начиная с 0 (актуально для СП типа A),  
nameLen | \- длина буфера строки.  
  
Выходные параметры:

name | \- имя исполнения.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Для групповой спецификации A или Б у объекта спецификации может быть несколько исполнений.

2\. Количество исполнений настраивается в настройке стиля спецификации. По умолчанию имя исполнения формируется из номера исполнения: "-01", "-02" и т.д. Имя исполнения можно отредактировать вручную.

3\. Функция предназначена для получения имени исполнения.

4\. При использовании ANSI следует использовать функцию [ksGetSpcPerformanceName](ksgetspcperformancename.html).

Подразделы:

(отсутствуют)
