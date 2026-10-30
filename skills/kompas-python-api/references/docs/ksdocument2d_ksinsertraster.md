# ksInsertRaster - Вставить растровый объект

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Графические примитивы ](bt1730616.html) |  Scroll [ [ [ ](ksdocument2d_ksline.html "К следующему разделу")](bt1730616.html "На уровень выше")](ksdocument2d_kshatch.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksInsertRaster](ksinsertraster.html).

Синтаксис Automation:

long ksInsertRaster (LPDISPATCH param);

Входной параметр:

param | \- указатель на интерфейс растрового объекта [ksRasterParam](ksrasterparam.html).  
---|---  
  
Возвращаемое значение:

указатель на растровый объект | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Создается новый объект "Выносной элемент" в текущем виде и в текущем документе.

Подразделы:

(отсутствуют)
