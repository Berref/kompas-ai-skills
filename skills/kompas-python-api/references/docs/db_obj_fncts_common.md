# Функции работы с базами данных

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) |  Scroll [ [ [ ](closetextfile.html "К следующему разделу")](cn1731963.html "На уровень выше")](systemcontrolstop.html "К предыдущему разделу")  
---|---  
  
Функции работы с базами данных обеспечивают работу с базами данных, доступ к которым осуществляется через интерфейс ODBCODBC, и базами данных, сохраненными в формате текстового файла loa.

Работа с базой данных начинается с создания ее блока заголовка функцией [CreateDB](createdb.html). Блок заголовка базы данных является управляющей структурой, содержащей имя базы данных и ее параметры. Конкретная привязка блока заголовка к файлу базы данных осуществляется функцией [ConnectDB](connectdb.html), причем в процессе работы возможно его отсоединение и повторное связывание.

Перед выполнением запроса необходимо создать специальный буфер, называемый отношением. Структура задается блоком функций [Relation](relation.html).....[EndRelation](endrelation.html), внутри которого определяются перечень полей и их типы. Сам запрос задается функцией [DoStatement](dostatement.html), а его условие можно определить с помощью функции [Condition](condition.html) или [ConditionW](conditionw.html) (Unicode). После выполнения запроса можно последовательно получить с помощью функции [ReadRecord](readrecord.html) все записи базы данных, соответствующие условию запроса.

Подразделы:

[CloseTextFile - Закрыть текстовый файл запросов ](closetextfile.html)

[Condition - Задать новое условие запроса ](condition.html)

[ConditionW - Задать новое условие запроса (Unicode) ](conditionw.html)

[ConnectDB - Связать заголовок и базу данных ](connectdb.html)

[ConnectDBW - Связать заголовок и базу данных (Unicode) ](connectdbw.html)

[CreateDB - Создать блок заголовка базы данных ](createdb.html)

[CreateDBW - Создать блок заголовка базы данных (Unicode) ](createdbw.html)

[DeleteDB - Удалить блок заголовка базы данных ](deletedb.html)

[DisconnectDB - Отсоединить блок заголовка от базы данных ](disconnectdb.html)

[DoStatement - Выполнить запрос базы данных ](dostatement.html)

[DoStatementW - Выполнить запрос базы данных (Unicode) ](dostatementw.html)

[EndRelation - Завершить описание отношения ](endrelation.html)

[FreeStatement - Освободить запрос базы данных ](freestatement.html)

[GetColumnName - Считать имя колонки таблицы из базы данных ](getcolumnname.html)

[GetColumnNameW - Считать имя колонки таблицы из базы данных (Unicode) ](getcolumnnamew.html)

[GetTableName - Считать имя таблицы из базы данных ](gettablename.html)

[GetTableNameW - Считать имя таблицы из базы данных (Unicode) ](gettablenamew.html)

[IsODBCOkey - Проверить подключение ODBC ](isodbcokey.html)

[ksOpenTextFileEx - Открыть текстовый файл, в котором хранятся SQL запросы ](ksopentextfileex.html)

[ksOpenTextFileExW - Открыть текстовый файл, в котором хранятся SQL запросы (Unicode) ](ksopentextfileexw.html)

[OpenTextFile - Открыть текстовый файл запросов ](opentextfile.html)

[OpenTextFileW - Открыть текстовый файл запросов (Unicode) ](opentextfilew.html)

[RChar - Определить строковое поле в отношении ](rchar.html)

[RCharW - Определить строковое поле wchar_t[size] в отношении (Unicode) ](rcharw.html)

[RDouble - Определить double-поле в отношении ](rdouble.html)

[RDoubleW - Определить double-поле в отношении (Unicode) ](rdoublew.html)

[Relation - Создать новое отношение ](relation.html)

[RFloat - Определить в отношении поле типа float ](rfloat.html)

[RFloatW - Определить в отношении поле типа float (Unicode) ](rfloatw.html)

[RInt - Определить в отношении поле типа short int ](rint.html)

[RIntW - Определить в отношении поле типа short int (Unicode) ](rintw.html)

[RLong - Определить в отношении поле типа int или long int ](rlong.html)

[RLongW - Определить в отношении поле типа int или long int (Unicode) ](rlongw.html)

[ReadRecord - Получить запись базы данных ](readrecord.html)

[ReadStrFromTextFile - Считать строку из текстового файла запросов ](readstrfromtextfile.html)

[ReadStrFromTextFileW - Считать строку из текстового файла запросов (Unicode) ](readstrfromtextfilew.html)
