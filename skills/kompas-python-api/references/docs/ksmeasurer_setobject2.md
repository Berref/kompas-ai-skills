# SetObject2 - Задать второй объект

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Измерение расстояния и угла между двумя примитивами (Интерфейсы ksMeasurer, IMeasurer) ](ksmeasurer.html) > [IMeasurer - методы ](ksmeasurer_methods.html) |  Scroll [ [ [ ](istrackingpointsmeasurer.html "К следующему разделу")](ksmeasurer_methods.html "На уровень выше")](ksmeasurer_setobject1.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksmeasurer.html)

Синтаксис Automation:

BOOL SetObject2 (LPDISPATCH obj);

Синтаксис COM:

BOOL SetObject2 (LPUNKNOWN obj);

Входной параметр:

obj | \- указатель на интерфейс IDispatch или IUnknown первого объекта.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Входным параметром может быть грань, ребро, вершина.

Подразделы:

(отсутствуют)
