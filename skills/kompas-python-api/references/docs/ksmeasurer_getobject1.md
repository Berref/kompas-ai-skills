# GetObject1 - Получить первый объект

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Измерение расстояния и угла между двумя примитивами (Интерфейсы ksMeasurer, IMeasurer) ](ksmeasurer.html) > [IMeasurer - методы ](ksmeasurer_methods.html) |  Scroll [ [ [ ](ksmeasurer_getobject2.html "К следующему разделу")](ksmeasurer_methods.html "На уровень выше")](ksmeasurer_getpoint2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksmeasurer.html)

Синтаксис Automation:

LPDISPATCH GetObject1();

Синтаксис COM:

LPUNKNOWN GetObject1();

Возвращаемое значение:

| \- указатель на интерфейс IDispatch или IUnknown первого объекта.  
---|---  
  
Примечание:

Возвращаемым значением может быть указатель на интерфейс грани, ребра, вершины. Зная тип объекта, можно привеcти его интерфейс к конечному 3D интерфейсу.

Подразделы:

(отсутствуют)
