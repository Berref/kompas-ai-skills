# ksOpenTolerance - Открыть допуск формы для редактирования

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с таблицей ](table_toler_fncts_common.html) |  Scroll [ [ [ ](ksreadtablefromfile.html "К следующему разделу")](table_toler_fncts_common.html "На уровень выше")](ksopentable.html "К предыдущему разделу")  
---|---  
  
[Пример...](func_red_dop_formy_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksOpenTolerance](ksdocument2d_ksopentolerance.html).

Синтаксис:

int ksOpenTolerance (reference tolerance);

Входной параметр:

tolerance | \- указатель на допуск формы.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Чтобы завершить редактирование допуска формы, нужно вызвать функцию [EndObj](endobj.html).

Подразделы:

(отсутствуют)
