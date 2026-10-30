# GetPoint1 - Получить ближайшую точку на первом объекте или на продолжении объекта

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Измерение расстояния и угла между двумя примитивами (Интерфейсы ksMeasurer, IMeasurer) ](ksmeasurer.html) > [IMeasurer - методы ](ksmeasurer_methods.html) |  Scroll [ [ [ ](ksmeasurer_getpoint2.html "К следующему разделу")](ksmeasurer_methods.html "На уровень выше")](ksmeasurer_getnormalpoint2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksmeasurer.html)

Синтаксис Automation:

BOOL GetPoint1 (double *x, double *y, double *z);

Синтаксис COM:

BOOL GetPoint1 (double *x, double *y, double *z);

Входной параметр:

x, y, z | \- координаты точки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Значения x, y, z возвращаются в системе координат компонента.

Подразделы:

(отсутствуют)
