# type - Тип объекта модели

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [IFeature - свойства ](ksfeature_props.html) |  Scroll [ [ [ ](ksfeature_updatestamp.html "К следующему разделу")](ksfeature_props.html "На уровень выше")](ksfeature_objecterror.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfeature.html)

Тип данных: short

Синтаксис Automation:

type = iFeature.type | Получить свойство ([* ](1.html))  
---|---  
type = iFeature.GetType() | Получить свойство ([**](2.html))  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Тип возвращаемого объекта может принимать значения:

o3d_part | \- деталь, |   
---|---|---  
o3d_entity | \- объект, |   
o3d_mateConstraint | \- сопряжение, |   
o3d_body | -тело. | [IBody](ksbody.html)[ ](ksbody.html)[или ](ksbody.html)[ksBody](ksbody.html)[.](ksbody.html)  
  
Выбирается из [Obj3dType](obj3dtype.html).

Подразделы:

(отсутствуют)
