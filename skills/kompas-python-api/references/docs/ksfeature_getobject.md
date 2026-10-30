# GetObject - Получить объект модели, связанный с объектом дерева

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [IFeature - методы ](ksfeature_methods.html) |  Scroll [ [ [ ](ksfeature_getownerfeature.html "К следующему разделу")](ksfeature_methods.html "На уровень выше")](ksfeature_entitycollection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfeature.html)

Синтаксис Automation:

LPDISPATCH GetObject();

Синтаксис COM:

LPUNKNOWN GetObject();

Возвращаемое значение:

| \- указатель на интерфейс объекта.  
---|---  
  
Примечание:

Тип возвращаемого объекта выбирается из [Obj3dType](obj3dtype.html). Может принимать значение:

o3d_part | \- деталь, |   
---|---|---  
o3d_entity | \- объект, |   
o3d_mateConstraint | \- сопряжение, |   
o3d_body | -тело | [IBody](ksbody.html)[ или ](ksbody.html)[kIsBody](ksbody.html)  
  
Подразделы:

(отсутствуют)
