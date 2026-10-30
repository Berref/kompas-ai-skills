# ksHatchByParam - Создать штриховку с заданными параметрами

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_ksinitfilepreviewfunc.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_ksgetshelfpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksHatch](kshatch.html).

Синтаксис Automation:

long ksHatchByParam (LPDISPATCH param);

Входной параметр:

param | \- указатель на интерфейс [ksHatchParam](kshatchparam.html).  
---|---  
  
Возвращаемое значение:

указатель на штриховку | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Объекты границы штриховки лежат во временной группе [ksHatchParam::boundaries](kshatchparam_boundaries.html). После выполнения метода [ksDocument2D::ksHatchByParam](ksdocument2d_kshatchbyparam.html) временная группа прекращает свое существование.

Подразделы:

(отсутствуют)
