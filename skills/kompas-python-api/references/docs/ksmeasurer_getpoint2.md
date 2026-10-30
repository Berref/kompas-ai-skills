# GetPoint2 - Получить ближайшую точку на втором объекте или на продолжении объекта

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Измерение расстояния и угла между двумя примитивами (Интерфейсы ksMeasurer, IMeasurer) ](ksmeasurer.html) > [IMeasurer - методы ](ksmeasurer_methods.html) |  Scroll [ [ [ ](ksmeasurer_getobject1.html "К следующему разделу")](ksmeasurer_methods.html "На уровень выше")](ksmeasurer_getpoint1.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksmeasurer.html)

Синтаксис Automation:

BOOL GetPoint2 (double *x, double *y, double *z);

Синтаксис COM:

BOOL GetPoint2 (double *x, double *y, double *z);

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
