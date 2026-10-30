# CreateSheetView - Создать новый вид в чертеже

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с видами ](cm1826821.html) > [Функции работы с видами ](views_fncts_common.html) |  Scroll [ [ [ ](createsheetvieww.html "К следующему разделу")](views_fncts_common.html "На уровень выше")](views_fncts_common.html "К предыдущему разделу")  
---|---  
  
[Пример...](createsheetview_openview_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksCreateSheetView](ksdocument2d_kscreatesheetview.html).

Синтаксис:

reference CreateSheetView(ViewParam *par,

int *number);

Входные параметры:

number | \- номер вида.  
---|---  
  
Выходные параметры:

par | \- указатель на структуру параметров вида,  
---|---  
  
Возвращаемое значение:

указатель на вид | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Созданный вид становится текущим.

2\. Если указать *number = 0, то создается вид с номером по возрастанию.

3\. Если *number = n, создается вид с номером n. Если вид n существует, ничего не создается (reference = 0) - ошибка.

4\. При использовании Unicode следует использовать функцию [CreateSheetViewW](createsheetvieww.html).

Подразделы:

(отсутствуют)
