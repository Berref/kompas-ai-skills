# GetNormalPoint1 - Получить первую точку отрезка расстояния по нормали

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Измерение расстояния и угла между двумя примитивами (Интерфейсы ksMeasurer, IMeasurer) ](ksmeasurer.html) > [IMeasurer - методы ](ksmeasurer_methods.html) |  Scroll [ [ [ ](ksmeasurer_getnormalpoint2.html "К следующему разделу")](ksmeasurer_methods.html "На уровень выше")](ksmeasurer_getminpoint2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksmeasurer.html)

Синтаксис Automation:

BOOL GetNormalPoint1 (double *x,

double *y,

double *z);

Синтаксис COM:

BOOL GetNormalPoint1 (double *x,

double*y,

double*z);

Выходные параметры:

x, y, z | \- координаты точки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод доступен после вызова метода [ksMeasurer::Calc](ksmeasurer_calc.html) (Automation) или [IMeasurer::Calc](ksmeasurer_calc.html) (COM).

Подразделы:

(отсутствуют)
