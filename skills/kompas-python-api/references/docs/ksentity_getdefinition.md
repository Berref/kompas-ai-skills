# GetDefinition - Получить указатель на интерфейс параметров объектов и элементов

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [ksEntity - методы ](ksentity_methods.html) |  Scroll [ [ [ ](ksentity_getfeature.html "К следующему разделу")](ksentity_methods.html "На уровень выше")](ksentity_getbodyparts.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksentity.html)

Синтаксис Automation:

LPDISPATCH GetDefinition();

Возвращаемое значение:

| \- указатель на интерфейс IDispatch.  
---|---  
  
Синтаксис COM:

LPUNKNOWN GetDefinition();

Возвращаемое значение:

| \- указатель на интерфейс IUnknown.  
---|---  
  
Примечание:

1\. Для доступа к параметрам объекта полученный интерфейс необходимо привести к соответствующему типу.

[Интерфейсы элементов модели...](model_elements.html)

2\. Интерфейсы параметров объектов и элементов выбираются из перечня [Obj3dType](obj3dtype.html).

Подразделы:

(отсутствуют)
