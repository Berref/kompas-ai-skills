# ksCreateSheetRemoteViewW - Создать ассоциативный выносной вид (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с видами ](cm1826821.html) > [Функции работы с видами ](views_fncts_common.html) |  Scroll [ [ [ ](ksgetqualitynames.html "К следующему разделу")](views_fncts_common.html "На уровень выше")](kscreatesheetremoteview.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksCreateSheetRemoteView](ksdocument2d_kscreatesheetremoteview.html).

Синтаксис:

reference LIB_FUNC ksCreateSheetRemoteViewW (AssociationViewParamW *par,

int *number,

reference obj);

Входные параметры:

par | \- структура параметров ассоциативного вида [AssociationViewParam](structassociationviewparam.html),  
---|---  
number | \- номер создаваемого вида,  
obj | \- указатель на объект "Обозначение выносного элемента".  
  
Возвращаемое значение:

указатель на вид | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. Созданный вид становится текущим.

2\. Объект "Обозначение выносного элемента" должен быть построен в ассоциативном виде. Этот вид будет базовым для создаваемого вида.

3\. Если значение параметра number = 0, то создается вид с номером по возрастанию.

4\. Если значение параметра *number = n, где n = 1 … 255, то создается вид с номером n. Если вид n существует, то ничего не создается.

5\. При использовании ANSI следует использовать функцию [ksCreateSheetRemoteView](kscreatesheetremoteview.html).

Подразделы:

(отсутствуют)
