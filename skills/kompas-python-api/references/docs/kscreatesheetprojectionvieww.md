# ksCreateSheetProjectionViewW - Создать проекционный ассоциативный вид (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с видами ](cm1826821.html) > [Функции работы с видами ](views_fncts_common.html) |  Scroll [ [ [ ](kscreatesheetsectionview.html "К следующему разделу")](views_fncts_common.html "На уровень выше")](kscreatesheetprojectionview.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksCreateSheetProjectionView](ksdocument2d_kscreatesheetprojectionview.html).

Синтаксис:

reference LIB_FUNC ksCreateSheetProjectionViewW( AssociationViewParamW * par,

int * number,

reference view);

Входные параметры:

par | \- структура параметров ассоциативного вида [AssociationViewParam](structassociationviewparam.html),  
---|---  
number | \- номер создаваемого вида,  
view | \- указатель на базовый вид.  
  
Возвращаемое значение:

указатель на вид | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. Созданный вид становится текущим.

2\. Базовый вид должен быть ассоциативным.

3\. Если значение параметра number = 0, то создается вид с номером по возрастанию.

4\. Если значение параметра *number = n, где n = 1 … 255, то создается вид с номером n. Если вид n существует, то ничего не создается.

5\. При использовании ANSI следует использовать функцию [ksCreateSheetProjectionView](kscreatesheetprojectionview.html).

Подразделы:

(отсутствуют)
