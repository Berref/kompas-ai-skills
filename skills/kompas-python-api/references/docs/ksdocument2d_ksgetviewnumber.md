# ksGetViewNumber - Получить номер вида по указателю на вид

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Оформление чертежа ](bt1730281.html) |  Scroll [ [ [ ](ksdocument2d_ksgetviewreference.html "К следующему разделу")](bt1730281.html "На уровень выше")](ksdocument2d_ksgetreferencedocumentpartex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [GetViewNumber](getviewnumber.html).

Синтаксис Automation:

long ksGetViewNumber (long p);

Входной параметр:

p | \- указатель на вид.  
---|---  
  
Возвращаемое значение:

номер вида | \- в случае удачного завершения,  
---|---  
-1 | \- в случае неудачи.  
  
Примечание:

Если p - указатель на вид или объект вида, возвращается номер вида этого объекта.

Подразделы:

(отсутствуют)
