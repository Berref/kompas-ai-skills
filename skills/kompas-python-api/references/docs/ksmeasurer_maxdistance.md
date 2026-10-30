# MaxDistance - Получить максимальное расстояние

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Измерение расстояния и угла между двумя примитивами (Интерфейсы ksMeasurer, IMeasurer) ](ksmeasurer.html) > [IMeasurer - методы ](ksmeasurer_methods.html) |  Scroll [ [ [ ](ksmeasurer_measureresult.html "К следующему разделу")](ksmeasurer_methods.html "На уровень выше")](ksmeasurer_isanglevalid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksmeasurer.html)

Синтаксис Automation:

double MaxDistance();

Синтаксис COM:

double MaxDistance();

Возвращаемое значение:

\- Максимальное расстояние между объектами (двумя гранями, гранью и ребром и т. п.)  
---  
  
Примечание:

Метод доступен после вызова метода [ksMeasurer::Calc](ksmeasurer_calc.html) (Automation) или [IMeasurer::Calc](ksmeasurer_calc.html) (COM).

Подразделы:

(отсутствуют)
