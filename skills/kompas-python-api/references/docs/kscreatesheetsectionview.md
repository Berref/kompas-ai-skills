# ksCreateSheetSectionView - Создать ассоциативный вид разреза/сечения

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с видами ](cm1826821.html) > [Функции работы с видами ](views_fncts_common.html) |  Scroll [ [ [ ](kscreatesheetsectionvieww.html "К следующему разделу")](views_fncts_common.html "На уровень выше")](kscreatesheetprojectionvieww.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksCreateSheetSectionView](ksdocument2d_kscreatesheetsectionview.html).

Синтаксис:

reference ksCreateSheetSectionView (AssociationViewParam *par,

int *number,

reference obj);

Входные параметры:

par | \- структура параметров ассоциативного вида [AssociationViewParam](structassociationviewparam.html),  
---|---  
number | \- номер создаваемого вида,  
obj | \- указатель на объект "линия разреза".  
  
Возвращаемое значение:

указатель на вид | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. Созданный вид становится текущим.

2\. Объект "линия разреза" должен быть построен в ассоциативном виде. Этот вид будет базовым для создаваемого вида.

3\. Если значение параметра number = 0, то создается вид с номером по возрастанию.

4\. Если значение параметра *number = n, где n = 1 … 255, то создается вид с номером n. Если вид n существует, то ничего не создается.

5\. При использовании Unicode следует использовать функцию [ksCreateSheetSectionViewW](kscreatesheetsectionvieww.html).

Подразделы:

(отсутствуют)
