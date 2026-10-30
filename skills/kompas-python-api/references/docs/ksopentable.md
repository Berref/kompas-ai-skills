# ksOpenTable - Oткрыть составной объект-таблицу для редактирования

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с таблицей ](table_toler_fncts_common.html) |  Scroll [ [ [ ](ksopentolerance.html "К следующему разделу")](table_toler_fncts_common.html "На уровень выше")](ksgettolerancecolumntext.html "К предыдущему разделу")  
---|---  
  
[Пример...](rab_with_tab_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksOpenTable](ksdocument2d_ksopentable.html).

Синтаксис:

int ksOpenTable (reference table);

Входной параметр:

table | \- указатель на таблицу.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Чтобы закрыть редактирование таблицы, нужно вызвать функцию [EndObj](endobj.html).

Подразделы:

(отсутствуют)
