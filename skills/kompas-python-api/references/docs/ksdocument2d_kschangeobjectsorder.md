# ksChangeObjectsOrder - Изменить порядок отрисовки объектов чертежа

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_kscolouringex.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_kschangeobjectinlibrequest.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksChangeObjectsOrder](kschangeobjectsorder.html).

Синтаксис Automation:

long ksChangeObjectsOrder (long group, long obj, int orderType);

Входные параметры:

group | \- указатель на группу объектов, для которой требуется изменить последовательность отрисовки,  
---|---  
obj | \- указатель на объект, относительно которого изменяется отрисовка группы,  
orderType | \- [Тип изменения порядка объектов](changeordertype.html).  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
