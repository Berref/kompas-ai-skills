# ksCloseDocument - Закрыть документ (чертеж, фрагмент, спецификацию, текстовый документ, деталь, сборку)

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Оформление чертежа ](bt1730281.html) |  Scroll [ [ [ ](ksdocument2d_ksclosetechnicaldemand.html "К следующему разделу")](bt1730281.html "На уровень выше")](bt1730281.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [CloseDocument](closedocument.html).

Синтаксис Automation:

BOOL ksCloseDocument();

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Если документ не сохранили, взводится флаг соответствующей ошибки.

Подразделы:

(отсутствуют)
