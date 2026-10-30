# ksCreateSheetArrowView - Создать ассоциативный вид по стрелке

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с видами ](cm1826821.html) > [Функции работы с видами ](views_fncts_common.html) |  Scroll [ [ [ ](kscreatesheetarrowvieww.html "К следующему разделу")](views_fncts_common.html "На уровень выше")](kscreatesheetarbitraryvieww.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksCreateSheetArrowView](ksdocument2d_kscreatesheetarrowview.html).

Синтаксис:

reference ksCreateSheetArrowView ( AssociationViewParam *par,

int *number,

reference obj);

Входные параметры:

par | \- структура параметров ассоциативного вида [AssociationViewParam](structassociationviewparam.html),  
---|---  
number | \- номер создаваемого вида,  
obj | \- указатель на объект "стрелка вида".  
  
Возвращаемое значение:

указатель на вид | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. Созданный вид становится текущим.

2\. Объект "стрелка вида" должен быть построен в ассоциативном виде. Этот вид будет базовым для создаваемого вида.

3\. Если значение параметра number = 0, то создается вид с номером по возрастанию.

4\. Если значение параметра *number = n, где n = 1 … 255, то создается вид с номером n. Если вид n существует, то ничего не создается.

5\. При использовании Unicode следует использовать функцию [ksCreateSheetArrowViewW](kscreatesheetarrowvieww.html).

Подразделы:

(отсутствуют)
