# ksCreateSheetView - Создать вид

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Оформление чертежа ](bt1730281.html) |  Scroll [ [ [ ](ksdocument2d_ksgetdocoptions.html "К следующему разделу")](bt1730281.html "На уровень выше")](ksdocument2d_kscreatedocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [CreateSheetView](createsheetview.html).

Синтаксис Automation:

long ksCreateSheetView (LPDISPATCH par, long* number);

Входные параметры:

par | \- указатель на интерфейс параметров вида [ksViewParam](ksviewparam.html),  
---|---  
number | \- номер вида.  
  
Возвращаемое значение:

указатель на вид | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Созданный вид становится текущим.

Если вид с указанным номером уже существует, новый вид не создается (ошибка).

Если указать *number = 0, то создается вид с номером по возрастанию.

Подразделы:

(отсутствуют)
