# SelectByPoint - Исключить из массива все объекты, не содержащие точку с заданными координатами

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Массив объектов модели (Интерфейсы ksEntityCollection и IEntityCollection) ](ksentitycollection.html) > [ksEntityCollection - методы ](ksentitycollection_methods.html) |  Scroll [ [ [ ](bw1897880.html "К следующему разделу")](ksentitycollection_methods.html "На уровень выше")](ksentitycollection_setbyindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksentitycollection.html)

Синтаксис Automation:

BOOL SelectByPoint (double x,

double y,

double z);

Синтаксис COM:

BOOL SelectByPoint (double x,

double y,

double z);

Входные параметры:

x, y, z | \- координаты точки,  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

После выполнения этой функции в массиве останутся только те объекты, которые содержат указанную точку (проходят через нее).

Данная функция временно не работает для формообразующих элементов (элементов выдавливания, вращения, по сечениям).

Подразделы:

(отсутствуют)
