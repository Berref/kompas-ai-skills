# ksCreateDocument - Создать документ (чертеж, фрагмент, текстовый документ, деталь, сборку)

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Оформление чертежа ](bt1730281.html) |  Scroll [ [ [ ](ksdocument2d_kscreatesheetview.html "К следующему разделу")](bt1730281.html "На уровень выше")](ksdocument2d_ksclosetechnicaldemand.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [CreateDocument](createdocument.html).

Синтаксис Automation:

BOOL ksCreateDocument (LPDISPATCH par);

Входной параметр:

par | \- указатель на интерфейс параметров документа [ksDocumentParam](ksdocumentparam.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Созданный документ становится текущим.

Подразделы:

(отсутствуют)
