# ksCreateSheetArbitraryView - Создать произвольный ассоциативный вид

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с видами ](cm1826821.html) > [Функции работы с видами ](views_fncts_common.html) |  Scroll [ [ [ ](kscreatesheetarbitraryvieww.html "К следующему разделу")](views_fncts_common.html "На уровень выше")](ksassociationviewmatrix3d.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksCreateSheetArbitraryView](ksdocument2d_kscreatesheetarbitraryview.html).

Синтаксис:

reference ksCreateSheetArbitraryView (AssociationViewParam * par, int *number);

Входные параметры:

number | \- номер создаваемого вида.  
---|---  
par | \- структура параметров ассоциативного вида [AssociationViewParam](structassociationviewparam.html).  
  
Возвращаемое значение:

указатель на вид | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. Созданный вид становится текущим.

2\. Если значение параметра number = 0, то создается вид с номером по возрастанию.

3\. Если значение параметра *number = n, где n = 1 … 255, то создается вид с номером n. Если вид n существует, то ничего не создается.

4\. При использовании Unicode следует использовать функцию [ksCreateSheetArbitraryViewW](kscreatesheetarbitraryvieww.html).

Подразделы:

(отсутствуют)
