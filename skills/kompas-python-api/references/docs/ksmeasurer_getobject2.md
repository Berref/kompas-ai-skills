# GetObject2 - Получить второй объект

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Измерение расстояния и угла между двумя примитивами (Интерфейсы ksMeasurer, IMeasurer) ](ksmeasurer.html) > [IMeasurer - методы ](ksmeasurer_methods.html) |  Scroll [ [ [ ](ksmeasurer_isanglevalid.html "К следующему разделу")](ksmeasurer_methods.html "На уровень выше")](ksmeasurer_getobject1.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksmeasurer.html)

Синтаксис Automation:

LPDISPATCH GetObject2();

Синтаксис COM:

LPUNKNOWN GetObject2();

Возвращаемое значение:

| \- указатель на интерфейс IDispatch или IUnknown второго объекта.  
---|---  
  
Примечание:

Возвращаемым значением может быть указатель на интерфейс грани, ребра, вершины. Зная тип объекта, можно привести его интерфейс к конечному 3D интерфейсу.

Подразделы:

(отсутствуют)
