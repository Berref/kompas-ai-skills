# ksSetTableColumnText - Задать текст ячейки таблицы

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Простановка текстовых надписей ](cm1738402.html) > [Функции работы с текстовыми надписями и таблицами ](text_labels_fncts_common.html) |  Scroll [ [ [ ](kssettextalign.html "К следующему разделу")](text_labels_fncts_common.html "На уровень выше")](ksgettextalign.html "К предыдущему разделу")  
---|---  
  
[Пример...](kssettablecolumntext_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksSetTableColumnText](ksdocument2d_kssettablecolumntext.html).

Синтаксис:

int ksSetTableColumnText (unsigned int numb, TextParam *par);

Входные параметры:

numb | \- номер ячейки,  
---|---  
  
Выходные параметры:

par | \- указатель на структуру параметров строки текста [TextParam](structtextparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Функция используется в режиме редактирования таблицы:

ksOpenTable ();

ksSetTableColumnText ();

EndObj ();

Подразделы:

(отсутствуют)
