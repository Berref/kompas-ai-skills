# ksCreateSheetProjectionView - Создать проекционный ассоциативный вид

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Создание видов ](bt1730395.html) |  Scroll [ [ [ ](ksdocument2d_kscreatesheetremoteview.html "К следующему разделу")](bt1730395.html "На уровень выше")](ksdocument2d_kscreatesheetarrowview.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksCreateSheetStandartViews](kscreatesheetstandartviews.html).

Синтаксис Automation:

long ksCreateSheetProjectionView (LPDISPATCH par, long * number, long view);

Входные параметры:

par | \- указатель на интерфейс [ksAssociationViewParam](ksassociationviewparam.html) параметров ассоциативного вида,  
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

Подразделы:

(отсутствуют)
