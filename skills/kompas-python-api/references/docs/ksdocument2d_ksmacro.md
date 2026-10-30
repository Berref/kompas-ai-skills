# ksMacro - Создать новый макроэлемент

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Составные объекты ](bt1730612.html) |  Scroll [ [ [ ](ksdocument2d_ksopenmacro.html "К следующему разделу")](bt1730612.html "На уровень выше")](ksdocument2d_ksgetmacrowaitdblclickedit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [Macro](macro.html).

Синтаксис Automation:

long ksMacro (short type);

Входной параметр:

type | \- тип макроэлемента: 0 - объединяет объекты текущего слоя, 1- включаемые объекты могут принадлежать разным слоям.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Макроэлемент - составной объект.

Объекты вида, вводимые между методами ksDocument2D::ksMacro и [ksDocument2D::ksEndObj](ksdocument2d_ksendobj.html), принадлежат макроэлементу. ksDocument2D::ksEndObj возвращает указатель на макроэлемент.

Подразделы:

(отсутствуют)
